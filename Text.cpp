#include "Text.h"

Text::Text(SDL_Renderer* renderer, const char* text, const SDL_Color& color, const std::string& id)
	: Asset(id)
{
	TTF_Font* font = TTF_OpenFont("Assets/Text/jokerman.ttf", 15);
	Configuration::getInstance()->assertEX(font, "Load font");

	SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
	Configuration::getInstance()->assertEX(surface, "Surface from font");

	_text = SDL_CreateTextureFromSurface(renderer, surface);
	Configuration::getInstance()->assertEX(_text, "Create texture from surface");

	SDL_FreeSurface(surface);
}

Text::~Text()
{
	SDL_DestroyTexture(_text);
}

void Text::render(SDL_Renderer* renderer, const Vector_2D& translation)
{
	SDL_Rect destination = { (int)translation.get_x(),
		(int)translation.get_y(),
		0,
		0 };
	SDL_QueryTexture(_text, nullptr, nullptr, &destination.w, &destination.h);
	SDL_RenderCopy(renderer, _text, nullptr, &destination);
}
