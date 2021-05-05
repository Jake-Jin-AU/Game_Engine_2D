#include "Camera.h"
#include "Game_Object.h"

Camera::Camera(const std::string& game_object_ID)
    : _target_ID(game_object_ID), _width(800), _height(600), _y(0.f)
{
}

Camera::~Camera()
{
}

//void Camera::update(const Game_Object* game_object, const int& w, const int& h)
//{
//    // If a player position is higher than half of camera position
//    //if (game_object->get_translation().get_y() < _height / 2.f)
//    int difference = game_object->get_translation().get_y() - (_height / 2.f);
//    if (_y + difference < 0)
//        _y = 0;
//    else
//_y += difference;
//    
//
//         //Vector_2D(-w / 2.f, -h / 2.f + game_object->get_height() / 2.f) + game_object->get_translation();
//    
//}

const std::string& Camera::get_target_ID() const
{
    return _target_ID;
}

const float& Camera::get_camera_y() const
{
    return _y;
}

const int& Camera::get_width() const
{
    return _width;
}

const int& Camera::get_height() const
{
    return _height;
}

void Camera::set_camera_y(const float& y)
{
    _y = y;
}

//void Camera::set_camera_x(const float& x)
//{
//    _translation = Vector_2D(x, _translation.get_y());
//}

//void Camera::set_camera_translation(const Vector_2D& translation)
//{
//    _translation = Vector_2D(_translation.get_x(), y);
//}