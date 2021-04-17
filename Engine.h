#pragma once
#include <iostream>


#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

class Configuration;
class Assets;
class Scene;
class Input;

class Engine
{
public:
	Engine();
	~Engine();

	// Run all processes in the engine
	void simulate(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input) const;
	// Get a pointer of main window (read-only)
	SDL_Window* get_window() const;
	// Get a pointer of rendering context (read-only)
	SDL_Renderer* get_renderer() const;
	
private:
	// Simulate the game state with AI system
	void simulate_AI(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input) const;
	// Simulate the game state with physics
	void simulate_physics(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene) const;
	// Render scenes
	void render(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene) const;

	
	SDL_Window*		_window;
	SDL_Renderer*	_renderer;
};

