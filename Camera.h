#pragma once

#include "Assets.h"
#include "Vector_2D.h"

class Camera
{
public:
	Camera(const std::string& game_object_ID);
	~Camera();

	const std::string& get_target_ID() const;
	const Vector_2D& get_camera_translation() const;
	const int& get_width() const;
	const int& get_height() const;

	void set_camera_translation(const Vector_2D& translation);
	void set_camera_x(const float& x);
	void set_camera_y(const float& y);

private:
	int				_width;
	int				_height;
	Vector_2D		_translation;
	std::string		_target_ID;

	
};

