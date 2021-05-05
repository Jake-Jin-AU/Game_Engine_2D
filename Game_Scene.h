#pragma once
#include <string>

#include "Scene.h"

class Game_Scene : public Scene
{
public:
	Game_Scene();
	~Game_Scene();

	// Inherited via Scene
	virtual void update(SDL_Window* window) override;

};

