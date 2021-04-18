#include "Camera.h"

Camera::Camera(const std::string& game_object_ID)
    : _target_ID(game_object_ID), _width(800), _height(600), _translation(0.f, 0.f)
{
}

Camera::~Camera()
{
}

const std::string& Camera::get_target_ID() const
{
    return _target_ID;
}

const Vector_2D& Camera::get_camera_translation() const
{
    return _translation;
}

const int& Camera::get_width() const
{
    return _width;
}

const int& Camera::get_height() const
{
    return _height;
}

void Camera::set_camera_translation(const Vector_2D& translation)
{
    _translation = translation;
}

void Camera::set_camera_x(const float& x)
{
    _translation = Vector_2D(x, _translation.get_y());
}

void Camera::set_camera_y(const float& y)
{
    _translation = Vector_2D(_translation.get_x(), y);
}