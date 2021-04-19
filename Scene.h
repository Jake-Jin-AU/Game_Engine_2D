#pragma once
#include <iostream>
#include <map>
#include <vector>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "Camera.h"

class Game_Object;

class Scene
{
public:
	Scene(const std::string& id);
	~Scene();

	virtual void update(SDL_Window* window) = 0;

	Game_Object* get_game_object(const std::string& id);
	std::vector<Game_Object*> get_game_objects();
	const std::string& get_id() const;

	Camera* get_camera() const;
	const Vector_2D& get_global_translation();

	void set_global_translation(const Vector_2D& global_translation);

protected:
	Camera*								_camera;
	std::map<std::string, Game_Object*>	_game_objects;
	std::string							_id;
	int									_scene_width;
	int									_scene_height;
	Vector_2D							_global_translation;
};

