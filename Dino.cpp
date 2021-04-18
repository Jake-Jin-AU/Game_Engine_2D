#include "Dino.h"

Dino::Dino(const std::string& id)
	: Game_Object(id, "Texture.Dino", Layer::LAYER_5)
{
	_translation = Vector_2D(50.f, 50.f);

	// Collider
	_collider.set_radius(_width / 5.f);
	_collider.set_translation(Vector_2D(_width / 2.f, _height - (_collider.get_radius() / 2.f)));
}

Dino::~Dino()
{
}

void Dino::simulate_AI(const Uint32&, Assets*, Input*)
{
}
