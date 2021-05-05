#include "Scene.h"
#include "Game_Object.h"

Scene::Scene(const std::string& id)
	: _global_translation(0.f, 0.f)
{
	// Temporary values
	_scene_width	= 800;
	_scene_height	= 600;
	
	//
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

const Vector_2D& Scene::get_global_translation()
{
	return _global_translation;
}

Camera* Scene::get_camera() const
{
	return _camera;
}

void Scene::set_global_translation(const Vector_2D& global_translation)
{
	_global_translation = global_translation;
}

void Scene::add_game_object(Game_Object* game_object)
{
	_game_objects[game_object->get_id()] = game_object;
}

void Scene::remove_game_object(std::string id)
{
	_game_objects.erase(id);
}
