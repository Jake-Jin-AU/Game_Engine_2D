#pragma once
#include <iostream>
#include <map>
#include <vector>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "Game_Object.h"

class Scene
{
public:
	Scene(const std::string& id);
	~Scene();

	virtual void update(SDL_Window* window) = 0;

	const Game_Object* get_game_object(const std::string& id);
	const std::vector<Game_Object*> get_game_objects() const;

	const std::string& get_id() const;

protected:
	std::map<std::string, Game_Object*>	_game_objects;
	std::string							_id;
};

