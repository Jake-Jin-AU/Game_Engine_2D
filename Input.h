#pragma once
#include <iostream>
#include <map>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_syswm.h>

class Input
{
public:
	Input();
	~Input();

	enum class Button
	{
		// Window
		QUIT,
		DIALOG_CONFIGURATION,
		DISPLAY_GAME_OBJECTS_ID,
		DISPLAY_GAME_OBJECTS_POSITION,
		DISPLAY_COLLIDERS,


		// Key
		UP,
		DOWN,
		LEFT,
		RIGHT,

		// Action
		RUNNING
	};

	enum class Button_State
	{
		PRESSED,
		DOWN,
		RELEASED,
		UP
	};

	void load_input();
	bool is_button_state(const Button& type, const Button_State& state) const;

private:
	std::map<Button, Button_State> _button_state;
};

