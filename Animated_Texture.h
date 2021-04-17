#pragma once
#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>

//class Texture;
#include "Texture.h"
#include "Asset.h"

class Animated_Texture : public Texture
{
public:
	Animated_Texture(const std::string id, const std::string path, SDL_Renderer* renderer, int frame_count, Uint32 frame_duration_milliseconds);
	~Animated_Texture();

	void update_frame(const Uint32& milliseconds_to_simulate);
	void render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Rect* destination, const SDL_RendererFlip& flip) const override;

private:
	int			_frame_count;
	Uint32		_frame_duration_milliseconds;
	Uint32		_total_time_milliseconds;
	int			_current_frame;
};

