#include "Scene.h"
#include "Game_Object.h"

Scene::Scene(const std::string& id)
{
	_id = id;
}

Scene::~Scene()
{
}

Game_Object* Scene::get_game_object(const std::string& id)
{
	if (_game_objects.find(id) == _game_objects.end())
	{
		std::cout << "Attemped to find a game object that does not exist. ID: " << id << std::endl;
		exit(1);
	}

	return _game_objects[id];
}

std::vector<Game_Object*> Scene::get_game_objects()
{
	std::vector<Game_Object*> game_objects;

	for (auto key_value : _game_objects)
	{
		game_objects.push_back(key_value.second);
	}

	return game_objects;
}

const std::string& Scene::get_id() const
{
	return _id;
}
