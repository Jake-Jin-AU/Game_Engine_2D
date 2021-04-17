#pragma once
#include <iostream>
#include <fstream>

#define SDL_MAIN_HANDLED
#include <SDL.h>

class Configuration
{
public:
	static Configuration* getInstance();

	void assertEX(const int& result, const int& success, const char* error_msg) const;
	void assertEX(const void* result, const char* error_msg) const;
	void assertEX(const void* result, const char* error_msg, const char* param) const;
	const std::string& get_window_name();
	const std::string& get_title() const;
	const std::string& get_version() const;
	const int& get_window_position_x() const;
	const int& get_window_position_y() const;
	const int& get_resolution_width() const;
	const int& get_resolution_height() const;
	const Uint8& get_refresh_rate() const;

	void set_refresh_rate(const Uint8& refresh_rate);

private:
	Configuration();
	~Configuration();
	Configuration(const Configuration&);
	static Configuration* _instance;

	std::string			_window_name;
	std::string			_title;
	std::string			_version;
	int					_window_position_x;
	int					_window_position_y;
	int					_resolution_width;
	int					_resolution_height;
	Uint8				_refresh_rate;
};

