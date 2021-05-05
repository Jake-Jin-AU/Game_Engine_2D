#pragma once
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "Texture.h"
#include "Asset.h"

class Tile_Texture : public Texture
{
public:
	Tile_Texture(const std::string& id, const std::string& path, SDL_Renderer* renderer, int frame_count);
	~Tile_Texture();

	void set_frame(const int& frame_no);

	void render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Rect* destination, const SDL_RendererFlip& flip) const;

private:
	int _frame_count;
	int _frame_no;
};

