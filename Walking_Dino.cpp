#include "Walking_Dino.h"

Walking_Dino::Walking_Dino(const std::string& id)
	: Game_Object(id, "Texture.Dino.Walking", Layer::LAYER_5)
{
	_translation	= Vector_2D(150.f, 50.f);
	_velocity		= Vector_2D(0.02f, 0.f);

	// Collider
	_collider.set_radius(_width / 5.f);
	_collider.set_translation(Vector_2D(_width / 2.f, _height - (_collider.get_radius() / 2.f)));
}

Walking_Dino::~Walking_Dino()
{
}

void Walking_Dino::simulate_AI(const Uint32&, Assets*, Input*)
{
	
}

void Walking_Dino::render(const Uint32& milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, scene);
}
