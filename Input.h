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
		QUIT,

		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	enum class Button_State
	{
		PRESSED,
		DOWN,
		RELEASED,
		UP
	};

	void load();
	bool is_button_state(const Button& type, const Button_State& state) const;

private:
	std::map<Button, Button_State> _button_state;
};

