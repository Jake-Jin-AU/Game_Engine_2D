#include "Circle_2D.h"

Circle_2D::Circle_2D(const float& radius, const Vector_2D translation)
	: _translation(translation.get_x(), translation.get_y())
{
	_radius = radius;
}

const float& Circle_2D::get_radius() const
{
	return _radius;
}

Vector_2D Circle_2D::get_translation() const
{
	return _translation;
}

void Circle_2D::set_radius(const float& radius)
{
	_radius = radius;
}

void Circle_2D::set_translation(const Vector_2D& translation)
{
	_translation = translation;
}

float Circle_2D::calculate_intersection_depth(const Circle_2D& other)
{
	if (_radius == 0.f || other.get_radius() == 0.f)
	{
		return 0.f;
	}

	const float distance_to_other = (other.get_translation() - _translation).calculate_magnitude();

	if (distance_to_other < (_radius + other.get_radius()))
	{
		return (_radius + other.get_radius()) - distance_to_other;
	}
	else
	{
		return 0.f;
	}
}
