#include "Editor.h"
#include "resource.h"
#include "Player.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_syswm.h>

Editor::Editor(const std::wstring& window_name)
{
	_window = FindWindow(nullptr, window_name.c_str());
	if (_window == nullptr)
	{
		std::wcout << "Failed to find window. Window Name: " << window_name.c_str() << std::endl;
		exit(1);
	}

	_menu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
	if (_menu == nullptr)
	{
		std::cout << "Failed to create menu. " << std::endl;
		exit(1);
	}

	BOOL set_menu_result = SetMenu(_window, _menu);
	if (set_menu_result == 0)
	{
		std::cout << "Failed to set menu. " << std::endl;
		exit(1);
	}

	Uint8 event_state_result	= SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
	Uint8 event_state_success	= SDL_DISABLE;
	if (event_state_result != event_state_success)
	{
		std::cout << "Failed to enable Windows event state." << std::endl;
		exit(1);
	}
}

Editor::~Editor()
{
}

void Editor::update(Input*, Scene*)
{
}
