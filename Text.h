#pragma once
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>

#include "Texture.h"
#include "Asset.h"
#include "Vector_2D.h"

class Text : public Asset
{
public:
	Text(SDL_Renderer* renderer, const char* text, const SDL_Color& color, const std::string& id);
	~Text();

	void render(SDL_Renderer* renderer, const Vector_2D& translation);

private:
	SDL_Texture* _text;
};

