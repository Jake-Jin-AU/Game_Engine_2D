#include "Sound.h"
#include "Configuration.h"

Sound::Sound(const std::string& id, const std::string& path)
	: Asset(id)
{
	_sound = Mix_LoadWAV(path.c_str());
	if (_sound == nullptr)
	{
		std::cout << "Failed to load WAV. Path: " << path << std::endl;
		std::cout << "Mixer Error: " << Mix_GetError();
		exit(1);
	}
}

Mix_Chunk* Sound::get_sound()
{
	return _sound;
}
