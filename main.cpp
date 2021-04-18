#include <iostream>
#include <chrono>
#include <thread>
#include <limits>

#include "Configuration.h"
#include "Engine.h"
#include "Assets.h"
#include "Game_Scene.h"
#include "Input.h"
#include "Editor.h"
int String_to_WString(std::wstring& ws, const std::string& s)
{
	std::wstring ws_temp(s.begin(), s.end());
	ws = ws_temp;

	return 0;
}
int main()
{
	std::wstring window_name = L"";
	String_to_WString(window_name, Configuration::getInstance()->get_window_name());
	Engine* engine		= new Engine();
	Assets* assets		= new Assets(engine->get_renderer());
	Scene* game_scene	= new Game_Scene();
	Input* input		= new Input();
	Editor* editor		= new Editor(window_name);

	const Uint32 milliseconds_per_seconds	= 1000;
	const Uint32 frames_per_second			= Configuration::getInstance()->get_refresh_rate();
	const Uint32 frame_time_ms				= milliseconds_per_seconds / frames_per_second;
	

	Uint32 frame_start_time_ms	= 0;
	Uint32 frame_end_time_ms	= frame_time_ms;
	while (!input->is_button_state(Input::Button::QUIT, Input::Button_State::PRESSED))
	{
		Uint32 previous_frame_duration	= frame_end_time_ms - frame_start_time_ms;
		frame_start_time_ms				= SDL_GetTicks();
		
		input->load_input();
		editor->update(input, game_scene);
		engine->simulate(previous_frame_duration, assets, game_scene, input);

		if (input->is_button_state(Input::Button::UP, Input::Button_State::PRESSED))
		{
			std::cout << "UP PRESSED!" << std::endl;
		}
		if (input->is_button_state(Input::Button::LEFT, Input::Button_State::PRESSED))
		{
			std::cout << "LEFT PRESSED!" << std::endl;
		}
		if (input->is_button_state(Input::Button::DOWN, Input::Button_State::PRESSED))
		{
			std::cout << "DOWN PRESSED!" << std::endl;
		}
		if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::PRESSED))
		{
			std::cout << "RIGHT PRESSED!" << std::endl;
		}

		const Uint32 current_time_ms	= SDL_GetTicks();
		const Uint32 frame_duration_ms	= current_time_ms - frame_start_time_ms;
		if (frame_duration_ms < frame_time_ms)
		{
			const Uint32 time_to_sleep_for = frame_time_ms - frame_duration_ms;
			std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep_for));
		}

		frame_end_time_ms = SDL_GetTicks();
	}

	return 0;
}