#include "Assets.h"


Assets::Assets(SDL_Renderer* renderer)
{
    // Create 2D Circle collider texture
    {
        Texture* texture = new Texture("Texture.Collider.Circle_2D", "Assets/textures/circle_2d.png", renderer);
        _assets[texture->get_id()] = texture;
    }

    // Create Backgournd music
    {
        Sound* sound = new Sound("Sound.Music.Background", "Assets/Sounds/background.mp3");
        _assets[sound->get_id()] = sound;

        Mix_PlayChannel(0, sound->get_sound(), -1);
    }

    // Create walking effect sound
    {
        Sound* sound = new Sound("Sound.Effect.Walking", "Assets/Sounds/walking.wav");
        _assets[sound->get_id()] = sound;
    }

    // Create running effect sound
    {
        Sound* sound = new Sound("Sound.Effect.Running", "Assets/Sounds/running.wav");
        _assets[sound->get_id()] = sound;
    }

    // Create map tile texture
    {
        Texture* texture = new Texture("Texture.Map.Tile", "Assets/textures/tile.png", renderer);
        _assets[texture->get_id()] = texture;
    }

    //
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
        Animated_Texture* texture = new Animated_Texture("Texture.Player.Idle",
            "Assets/textures/player.idle.png",
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

    {
        const int frame_count = 10;
        const Uint32 frame_duration_milliseconds = 100;
        Animated_Texture* texture = new Animated_Texture("Texture.Player.Running",
            "Assets/textures/player.running.png",
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