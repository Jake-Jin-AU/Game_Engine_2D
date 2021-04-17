#include "Dino.h"

Dino::Dino(const std::string& id)
	: Game_Object(id, "Texture.Dino", Layer::LAYER_5)
{
	_translation = Vector_2D(50.f, 50.f);
}

Dino::~Dino()
{
}

void Dino::simulate_AI(const Uint32&, Assets*, Input*)
{
}
