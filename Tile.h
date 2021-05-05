#pragma once

#include "Game_Object.h"

class Tile : public Game_Object
{
public:
	Tile(const std::string& id, const int& tile_no, const Vector_2D& pos);
	~Tile();

	void set_tile_no(const int& tile_no);

	// Inherited via Game_Object
	virtual void simulate_AI(const Uint32& milliseconds_to_simulate, Assets* assets, Input* input) override;
	virtual void render(const Uint32& milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Scene* scene) override;

private:
	int _tile_no;
};

