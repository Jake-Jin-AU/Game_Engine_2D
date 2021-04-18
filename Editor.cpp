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

INT_PTR CALLBACK Dialog_Configuration_Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return true;
		
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		// controls message
		case IDOK:
			EndDialog(hWnd, IDOK);
			break;
		}
		break;

	default:
		return false;
	}

	return true;
}

void Editor::update(Input* input, Scene*)
{
	if (input->is_button_state(Input::Button::DIALOG_CONFIGURATION, Input::Button_State::PRESSED))
	{
		DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG_CONFIGURATION), _window, Dialog_Configuration_Proc);
	}

	if (input->is_button_state(Input::Button::DISPLAY_GAME_OBJECTS_ID, Input::Button_State::PRESSED))
	{
		Configuration::getInstance()->_should_display_ids = !Configuration::getInstance()->_should_display_ids;
	}

	if (input->is_button_state(Input::Button::DISPLAY_COLLIDERS, Input::Button_State::PRESSED))
	{
		Configuration::getInstance()->_should_display_colliders = !Configuration::getInstance()->_should_display_colliders;
	}
}
