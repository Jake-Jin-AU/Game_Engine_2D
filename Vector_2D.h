#pragma once
#include <math.h>

class Vector_2D
{
public:
	Vector_2D(float x, float y);

	const float& get_x() const;
	const float& get_y() const;
	
	void operator=(const Vector_2D& rhs);
	void operator+=(const Vector_2D& rhs);

	Vector_2D operator-(const Vector_2D& rhs);
	Vector_2D operator+(const Vector_2D& rhs);

	float calculate_magnitude() const;
	void normalise();
	void scale(const float& scalar);

private:
	float _x;
	float _y;
};

