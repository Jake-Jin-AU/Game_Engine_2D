#include "Tile.h"

Tile::Tile(const std::string& id, const int& tile_no, const Vector_2D& pos)
	: Game_Object(id, "Texture.Map.Tile", pos, Layer::LAYER_7)
{
	_tile_no = tile_no;

	//float radius = _width / 5.f;
	_width = 50;
	_height = 50;
	_rect_collider = new Rect_2D(pos.get_x(), pos.get_y(), (float)_width, (float)_height);
}

Tile::~Tile()
{
}

void Tile::set_tile_no(const int& tile_no)
{
	_tile_no = tile_no;
}

void Tile::simulate_AI(const Uint32&, Assets*, Input*)
{
}

void Tile::render(const Uint32& milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Scene* scene)
{
	Tile_Texture* texture = (Tile_Texture*)assets->get_asset(_texture_id);
	texture->set_frame(_tile_no);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, scene);
}
