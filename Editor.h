#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

#include "Input.h"
#include "Scene.h"
#include "Dino.h"

class Editor
{
public:
	Editor(const std::wstring& window_name);
	~Editor();

	void update(Input* input, Scene* scene);

private:
	HWND	_window;
	HMENU	_menu;
};

