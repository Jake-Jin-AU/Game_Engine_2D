#pragma once
#include "Collider.h"
#include "Vector_2D.h"

class Circle_2D : public Collider
{
public:
	Circle_2D(const float& radius, const Vector_2D translation);

	// Get
	const float& get_radius() const;
	Vector_2D get_translation() const;

	// Set
	void set_radius(const float& radius);
	void set_translation(const Vector_2D& translation);

	//
	float calculate_intersection_depth(const Circle_2D& other);
private:
	float		_radius;
	Vector_2D	_translation;
};

