#pragma once

#include "Collider.h"
#
class Rect_2D : public Collider
{
public:
	Rect_2D(const float& rx, const float& ry, const float& rw, const float& rh);

	const float& get_rect_x() const;
	const float& get_rect_y() const;
	const float& get_rect_w() const;
	const float& get_rect_h() const;
	//
	bool calculate_intersection_depth(const Rect_2D& other);

private:
	float _rx;	// x position
	float _ry;	// y position
	float _rw;	// width
	float _rh;	// height
};

