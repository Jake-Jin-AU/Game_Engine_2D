#include "Game_Scene.h"
#include "Dino.h"
#include "Walking_Dino.h"
#include "Player.h"
#include "Tile.h"

Game_Scene::Game_Scene()
	: Scene("Stage_1")
{
	// Camera
	{
		_scene_width	= 800;
		_scene_height	= 1200;

		Camera* camera = new Camera("Player");
		_camera = camera;

		//_camera->set_camera_translation(Vector_2D(_camera->get_width() / 2.f, _scene_height - (_camera->get_height() / 2.f)));
	}

	// Game Objects
	add_game_object(new Dino("Dino", Vector_2D(50.f, 50.f)));
	add_game_object(new Walking_Dino("Dino.Walking", Vector_2D(50.f, 440.f)));
	add_game_object(new Player("Player", Vector_2D(200.f, 400.f)));

	// Main ground
	const int size_of_tile = 50;
	int no_of_tiles = _scene_width / size_of_tile;
	for (int i = 0; i < no_of_tiles; i++)
	{
		std::string id = "Tile0-" + std::to_string(i);
		add_game_object(new Tile(id, 0, Vector_2D((float)(i * size_of_tile), 550.f)));
		id = "Tile1-" + std::to_string(i);
		add_game_object(new Tile(id, 1, Vector_2D((float)(i * size_of_tile), 500.f)));
	}

	// Obstacles
	no_of_tiles = 10;
	for (int i = 0; i < no_of_tiles; i++)
	{
		std::string id = "Tile2-" + std::to_string(i);
		add_game_object(new Tile(id, 2, Vector_2D(0.f, (float)(size_of_tile * -i + 450.f))));
		id = "Tile3-" + std::to_string(i);
		add_game_object(new Tile(id, 2, Vector_2D(750.f, (float)(size_of_tile * -i + 450.f))));
	}

	// Sub Ground
	for (int i = 0; i < 3; i++)
	{
		std::string id = "Tile4-" + std::to_string(i);
		add_game_object(new Tile(id, 1, Vector_2D((float)(i * size_of_tile) + 100.f, 200.f)));
	}

	for (int i = 0; i < 3; i++)
	{
		std::string id = "Tile5-" + std::to_string(i);
		add_game_object(new Tile(id, 1, Vector_2D((float)(i * size_of_tile) + 150.f, 300.f)));
	}

	for (int i = 0; i < 2; i++)
	{
		std::string id = "Tile6-" + std::to_string(i);
		add_game_object(new Tile(id, 1, Vector_2D((float)(i * size_of_tile) + 450.f, 300.f)));
	}

	for (int i = 0; i < 4; i++)
	{
		std::string id = "Tile7-" + std::to_string(i);
		add_game_object(new Tile(id, 1, Vector_2D((float)(i * size_of_tile) + 350.f, 150.f)));
	}

}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window* window)
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	//Game_Object* player = get_game_object("Player");

	//_camera->update(player, w, h);
	//_camera->set_camera_translation(Vector_2D(-w / 2.f + player->get_width() / 2.f, -h / 2.f + player->get_height() / 2.f) + player->get_translation());
}
