#include "Game_Scene.h"
#include "Dino.h"
#include "Walking_Dino.h"
#include "Player.h"

Game_Scene::Game_Scene()
	: Scene("Stage_1")
{
	// Camera
	{
		Camera* camera = new Camera("Player");
		_camera = camera;

		_camera->set_camera_translation(Vector_2D(_camera->get_width() / 2.f, _global_coordinate_height - (_camera->get_height() / 2.f)));
	}

	// Game Objects
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

void Game_Scene::update(SDL_Window* window)
{
	Game_Object* player = get_game_object("Player");

	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	_camera->set_camera_translation(Vector_2D(-w / 2.f + player->get_width() / 2.f, -h / 2.f + player->get_height() / 2.f) + player->get_translation());
}
