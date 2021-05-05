#pragma once
#include <iostream>

#include "Vector_2D.h"

//class Game_Object;

class Camera
{
public:
	Camera(const std::string& game_object_ID);
	~Camera();

	//void update(const Game_Object* game_object, const int& w, const int& h);

	const std::string& get_target_ID() const;
	const float& get_camera_y() const;
	const int& get_width() const;
	const int& get_height() const;

	//void set_camera_translation(const Vector_2D& translation);
	//void set_camera_x(const float& x);
	void set_camera_y(const float& y);

private:
	int				_width;
	int				_height;
	float			_y;
	std::string		_target_ID;

	
};

