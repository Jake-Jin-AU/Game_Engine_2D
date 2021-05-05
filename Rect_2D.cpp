#include "Rect_2D.h"

Rect_2D::Rect_2D(const float& rx, const float& ry, const float& rw, const float& rh)
	: _rx(rx), _ry(ry), _rw(rw), _rh(rh)
{

}

const float& Rect_2D::get_rect_x() const
{
	return _rx;
}

const float& Rect_2D::get_rect_y() const
{
	return _ry;
}

const float& Rect_2D::get_rect_w() const
{
	return _rw;
}

const float& Rect_2D::get_rect_h() const
{
	return _rh;
}

bool Rect_2D::calculate_intersection_depth(const Rect_2D& other)
{
	if (_rx + _rw >= other._rx &&
		_rx <= other._rx + other._rw &&
		_ry + _rh >= other._ry &&
		_ry <= other._ry + other._rh)
		return true;

	return false;
}
