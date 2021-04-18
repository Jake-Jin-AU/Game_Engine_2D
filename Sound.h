#pragma once

#include <SDL_mixer.h>

#include "Asset.h"

class Sound : public Asset
{
public:
	Sound(const std::string& id, const std::string& path);

	Mix_Chunk* get_sound();

private:
	Mix_Chunk* _sound;
};

