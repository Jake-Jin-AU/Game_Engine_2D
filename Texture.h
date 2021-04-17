#pragma once
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>

#include "Configuration.h"
#include "Asset.h"

class Texture : public Asset
{
public:
	Texture(const std::string& id, const std::string& path, SDL_Renderer* renderer);
	~Texture();

	SDL_Texture* get_texture() const;

	virtual void render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Rect* destination, const SDL_RendererFlip& flip) const;

private:
	SDL_Texture*	_texture;
};

