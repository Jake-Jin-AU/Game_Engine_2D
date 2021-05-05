#include "Input.h"
#include "resource.h"

Input::Input()
{
}

Input::~Input()
{
}

void Input::load_input()
{
	_button_state[Button::DIALOG_CONFIGURATION]				= Button_State::UP;
	_button_state[Button::DISPLAY_GAME_OBJECTS_ID]			= Button_State::UP;
	_button_state[Button::DISPLAY_GAME_OBJECTS_POSITION]	= Button_State::UP;
	_button_state[Button::DISPLAY_COLLIDERS]				= Button_State::UP;
	_button_state[Button::FILE_PAUSE]						= Button_State::UP;

	for (auto button_state : _button_state)
	{
		if (button_state.second == Button_State::PRESSED)
		{
			_button_state[button_state.first] = Button_State::DOWN;
		}
		else if (button_state.second == Button_State::RELEASED)
		{
			_button_state[button_state.first] = Button_State::UP;
		}
	}

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		// Application Events
		case SDL_QUIT:
			_button_state[Button::QUIT] = Button_State::PRESSED;
			break;

		// Window Events
		case SDL_SYSWMEVENT:
			if (event.syswm.msg->msg.win.wParam == ID_FILE_EXIT)
			{
				_button_state[Button::QUIT] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_FILE_PAUSE)
			{
				_button_state[Button::FILE_PAUSE] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_SETTINGS_CONFIGURATION)
			{
				_button_state[Button::DIALOG_CONFIGURATION] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_GAMEOBJECTS_TOGGLEDISPLAYID)
			{
				_button_state[Button::DISPLAY_GAME_OBJECTS_ID] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_GAMEOBJECTS_TOGGLEDISPLAYCOLLIDER)
			{
				_button_state[Button::DISPLAY_COLLIDERS] = Button_State::PRESSED;
			}
			else if (event.syswm.msg->msg.win.wParam == ID_GAMEOBJECTS_TOGGLEDISPLAYPOSITION)
			{
				_button_state[Button::DISPLAY_GAME_OBJECTS_POSITION] = Button_State::PRESSED;
			}
			break;

		// Key events
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_W:
				if (!is_button_state(Button::UP, Button_State::DOWN))
				{
					_button_state[Button::UP] = Button_State::PRESSED;
				}
				break;
				
			case SDL_SCANCODE_A:
				if (!is_button_state(Button::LEFT, Button_State::DOWN))
				{
					_button_state[Button::LEFT] = Button_State::PRESSED;
				}
				break;

			case SDL_SCANCODE_S:
				if (!is_button_state(Button::DOWN, Button_State::DOWN))
				{
					_button_state[Button::DOWN] = Button_State::PRESSED;
				}
				break;

			case SDL_SCANCODE_D:
				if (!is_button_state(Button::RIGHT, Button_State::DOWN))
				{
					_button_state[Button::RIGHT] = Button_State::PRESSED;
				}
				break;

			case SDL_SCANCODE_LSHIFT:
				if (!is_button_state(Button::RUNNING, Button_State::DOWN))
				{
					_button_state[Button::RUNNING] = Button_State::PRESSED;
				}
				break;

			case SDL_SCANCODE_SPACE:
				if (!is_button_state(Button::JUMPING, Button_State::DOWN))
				{
					_button_state[Button::JUMPING] = Button_State::PRESSED;
				}
				break;
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_W:
				_button_state[Button::UP] = Button_State::RELEASED;
				break;

			case SDL_SCANCODE_A:
				_button_state[Button::LEFT] = Button_State::RELEASED;
				break;

			case SDL_SCANCODE_S:
				_button_state[Button::DOWN] = Button_State::RELEASED;
				break;

			case SDL_SCANCODE_D:
				_button_state[Button::RIGHT] = Button_State::RELEASED;
				break;

			case SDL_SCANCODE_LSHIFT:
				_button_state[Button::RUNNING] = Button_State::RELEASED;
				break;
			case SDL_SCANCODE_SPACE:
				_button_state[Button::JUMPING] = Button_State::RELEASED;
				break;
			}
			break;
		}
	}

}

bool Input::is_button_state(const Button& type, const Button_State& state) const
{
	if (_button_state.find(type) == _button_state.end())
	{
		if (state == Button_State::UP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return _button_state.find(type)->second == state;
}
