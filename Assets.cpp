#include "Assets.h"


Assets::Assets(SDL_Renderer* renderer)
{
    {
        Texture* texture = new Texture("Texture.Dino", "Assets/textures/dino.png", renderer);
        _assets[texture->get_id()] = texture;
    }
    
    {
        const int frame_count = 10;
        const Uint32 frame_duration_milliseconds = 100;
        Animated_Texture* texture = new Animated_Texture("Texture.Dino.Walking",
            "Assets/textures/dino.walking.png",
            renderer,
            frame_count,
            frame_duration_milliseconds);
        _assets[texture->get_id()] = texture;
    }
    
    {
        const int frame_count = 10;
        const Uint32 frame_duration_milliseconds = 100;
        Animated_Texture* texture = new Animated_Texture("Texture.Player.Walking",
            "Assets/textures/player.walking.png",
            renderer,
            frame_count,
            frame_duration_milliseconds);
        _assets[texture->get_id()] = texture;
    }
}

Assets::~Assets()
{
}

const Asset* Assets::get_asset(const std::string& id)
{
    if (_assets.find(id) == _assets.end())
    {
        std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
        exit(1);
    }
    return _assets[id];
}