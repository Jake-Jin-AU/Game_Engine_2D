#include "Game_Scene.h"
#include "Dino.h"
#include "Walking_Dino.h"
#include "Player.h"

Game_Scene::Game_Scene()
	: Scene("Stage_1")
{
	{
		Game_Object* dino = new Dino("Dino");
		_game_objects[dino->get_id()] = dino;
	}
	
	{
		Game_Object* dino_walking = new Walking_Dino("Dino.Walking");
		_game_objects[dino_walking->get_id()] = dino_walking;
	}

	{
		Game_Object* player = new Player("Player");
		_game_objects[player->get_id()] = player;
	}
	
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}
