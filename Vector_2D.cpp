#include "Vector_2D.h"

Vector_2D::Vector_2D(float x, float y)
{
    _x = x;
    _y = y;
}

const float& Vector_2D::get_x() const
{
    return _x;
}

const float& Vector_2D::get_y() const
{
    return _y;
}

void Vector_2D::operator=(const Vector_2D& rhs)
{
    _x = rhs._x;
    _y = rhs._y;
}

void Vector_2D::operator+=(const Vector_2D& rhs)
{
    _x += rhs._x;
    _y += rhs._y;
}

void Vector_2D::operator-=(const Vector_2D& rhs)
{
    _x -= rhs._x;
    _y -= rhs._y;
}

Vector_2D Vector_2D::operator-(const Vector_2D& rhs)
{
    return Vector_2D(_x - rhs._x, _y - rhs._y);
}

Vector_2D Vector_2D::operator+(const Vector_2D& rhs)
{
    return Vector_2D(_x + rhs._x, _y + rhs._y);
}

float Vector_2D::calculate_magnitude() const
{
    return sqrtf(_x * _x + _y * _y);
}

void Vector_2D::normalise()
{
    float mag = calculate_magnitude();

    if (mag > 0.f)
    {
        _x /= mag;
        _y /= mag;
    }
}

void Vector_2D::set_scale(const float& scalar)
{
    _x *= scalar;
    _y *= scalar;
}

float Vector_2D::calculate_angle() const
{
    return -atan2f(_y, _x);
}