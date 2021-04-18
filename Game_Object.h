#pragma once
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "Assets.h"
#include "Input.h"
#include "Vector_2D.h"
#include "Text.h"
#include "Circle_2D.h"
#include "Scene.h"

enum class Layer
{
	LAYER_0,
	LAYER_1,
	LAYER_2,
	LAYER_3,
	LAYER_4,
	LAYER_5,
	LAYER_6,
	LAYER_7,
	LAYER_8,
	LAYER_9
};

class Game_Object
{
public:
	Game_Object(const std::string& id, const std::string& texture_id, const Layer layer);
	~Game_Object();

	// Get
	const std::string& get_id() const;
	const float& get_scale() const;
	const Vector_2D& get_translation() const;
	const Circle_2D& get_collider() const;

	// Set
	void set_scale(const float& scalar);

	//
	virtual void simulate_AI(const Uint32& milliseconds_to_simulate, Assets* assets, Input* input) = 0;
	virtual void simulate_physics(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene);
	virtual void render(const Uint32& milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer);

protected:
	std::string _id;
	std::string _texture_id;

	Layer		_layer;
	std::string _audio_id;	//?

	/*Transform* transform;
	Collier* collier;*/
	Vector_2D _translation;
	Vector_2D _velocity;
	Circle_2D _collider;

	int		_width;
	int		_height;
	float	_scale;

	SDL_RendererFlip _flip;

private:
};

