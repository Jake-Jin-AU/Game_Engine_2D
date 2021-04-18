#include "Engine.h"
#include "Configuration.h"
#include "Texture.h"
#include "Assets.h"
#include "Scene.h"
#include "Game_Object.h"
#include "Input.h"

Engine::Engine()
{
    // Initialise SDL
    Configuration::getInstance()->assertEX(SDL_Init(SDL_INIT_EVERYTHING),
        0,
        "Initialize SDL");
    
    // Create a window
    _window = SDL_CreateWindow(Configuration::getInstance()->get_window_name().c_str(),
        Configuration::getInstance()->get_window_position_x(),
        Configuration::getInstance()->get_window_position_y(),
        Configuration::getInstance()->get_resolution_width(),
        Configuration::getInstance()->get_resolution_height(),
        0);
    Configuration::getInstance()->assertEX(_window,
        "Create SDL window");

    // Create a renderer
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    Configuration::getInstance()->assertEX(_renderer,
        "Create a renderer");

    // Initialise SDL_image
    Configuration::getInstance()->assertEX(IMG_Init(IMG_INIT_PNG),
        IMG_INIT_PNG,
        "Initialise SDL image");

    // Initialise SDL_TTF
    Configuration::getInstance()->assertEX(TTF_Init(), 0, "Initialise SDL TTF");

    // Initialise Mixer
    const int mixer_init_result = Mix_Init(MIX_INIT_MOD);
    const int mixer_init_failure = 0;
    if (mixer_init_result == mixer_init_failure)
    {
        std::cout << "Failed to initialize SDL Mixer" << std::endl;
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        std::cout << "Mixer Error: " << Mix_GetError() << std::endl;
        exit(1);
    }

    const int mixer_open_audio_result = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    const int mixer_open_audio_success = 0;
    if (mixer_open_audio_result != mixer_open_audio_success)
    {
        std::cout << "Failed to open audio" << std::endl;
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    Mix_AllocateChannels(3);
}

Engine::~Engine()
{
}

void Engine::simulate(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input) const
{
    simulate_AI(milliseconds_to_simulate, assets,scene, input);
    simulate_physics(milliseconds_to_simulate, assets, scene);
    render(milliseconds_to_simulate, assets, scene);
}

SDL_Window* Engine::get_window() const
{
    return _window;
}

SDL_Renderer* Engine::get_renderer() const
{
    return _renderer;
}

void Engine::simulate_AI(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input) const
{
    std::vector<Game_Object*> game_objects = scene->get_game_objects();
    for (Game_Object* game_object : game_objects)
    {
        game_object->simulate_AI(milliseconds_to_simulate, assets, input);
    }
}

void Engine::simulate_physics(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene) const
{
    std::vector<Game_Object*> game_objects = scene->get_game_objects();
    for (Game_Object* game_object : game_objects)
    {
        game_object->simulate_physics(milliseconds_to_simulate, assets, scene);
    }
}

void Engine::render(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene) const
{
    // Clear a render
    Configuration::getInstance()->assertEX(SDL_RenderClear(_renderer),
        0,
        "Clear a render");

    // Set a render draw color
    const Uint8 red     = 0;
    const Uint8 green   = 128;
    const Uint8 blue    = 128;
    const Uint8 alpha   = 0;
    Configuration::getInstance()->assertEX(SDL_SetRenderDrawColor(_renderer, red, green, blue, alpha),
        0,
        "Set a render draw color");

    std::vector<Game_Object*> game_objects = scene->get_game_objects();
    for (Game_Object* game_object : game_objects)
    {
        game_object->render(milliseconds_to_simulate, assets, _renderer, scene);
    }

    // Present a render
    SDL_RenderPresent(_renderer);
}
