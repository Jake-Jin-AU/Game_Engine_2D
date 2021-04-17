#pragma once

#include <map>

#include "Texture.h"
#include "Animated_Texture.h"
#include "Asset.h"

class Assets
{
public:
	Assets(SDL_Renderer* renderer);
	~Assets();

	const Asset* get_asset(const std::string& id);

private:
	std::map<std::string, Asset*> _assets;
};

