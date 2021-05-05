#include "Dino.h"

Dino::Dino(const std::string& id, const Vector_2D& pos)
	: Game_Object(id, "Texture.Dino", pos, Layer::LAYER_5)
{
	//_translation = Vector_2D(50.f, 50.f);

	// Collider
	float radius = _width / 5.f;
	_circle_collider = new Circle_2D(radius, Vector_2D(_width / 2.f, _height - (radius / 2.f)));
	
	//_collider.set_radius(_width / 5.f);
	//_collider.set_translation(Vector_2D(_width / 2.f, _height - (_collider.get_radius() / 2.f)));
}

Dino::~Dino()
{
}

void Dino::simulate_AI(const Uint32&, Assets*, Input*)
{
}
