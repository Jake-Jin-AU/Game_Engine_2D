#include "Configuration.h"

Configuration* Configuration::_instance = nullptr;

Configuration::Configuration()
{
    // default
    _title = "Fly_Spider";
    _version = "1.0.0a";
    _window_position_x = 100;
    _window_position_y = 100;
    _resolution_width = 800;
    _resolution_height = 600;
    _refresh_rate = 60;

    // Read configuration file
    std::ifstream file;
    file.open("./x64/debug/Configuration.cfg");
    std::string w;
    std::string game_title;
    while (!file.eof())
    {
        file >> w;
        if (w.empty())
        {
            continue;
        }
        else if (w == "[title]")
        {
            file >> w;
            if (!w.empty())
                _title = w;
        }
        else if (w == "[version]")
        {
            file >> w;
            if (!w.empty())
                _version = w;
        }
        else if (w == "[window]")
        {
            file >> w;
            if (!w.empty())
                _window_position_x = atoi(w.c_str());
            file >> w;
            if (!w.empty())
                _window_position_y = atoi(w.c_str());
        }
        else if (w == "[resolution]")
        {
            file >> w;
            if (!w.empty())
                _resolution_width = atoi(w.c_str());
            file >> w;
            if (!w.empty())
                _resolution_height = atoi(w.c_str());
        }
        else if (w == "[refresh]")
        {
            file >> w;
            if (!w.empty())
                _refresh_rate = atoi(w.c_str());
        }
        else if (w == "[end]")
        {
            break;
        }
    }
    file.close();
    
    
    // Validate configuration file

}

Configuration::~Configuration()
{
}

Configuration* Configuration::get_instance()
{
    if (_instance == nullptr)
    {
        _instance = new Configuration();
    }
    
    return _instance;
}

void Configuration::assertEX(const int& result, const int& success, const char* function) const
{
    if (success != result)
    {
        std::cout << "Failed to " << function << "\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Configuration::assertEX(const void* result, const char* error_msg) const
{
    if (result == nullptr)
    {
        std::cout << "Failed to " << error_msg << "\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void Configuration::assertEX(const void* result, const char* error_msg, const char* param) const
{
    if (result == nullptr)
    {
        std::cout << "Failed to " << error_msg << " " << param << "\n";
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

const std::string& Configuration::get_window_name()
{
    _window_name = _title + " - " + _version;
    return _window_name;
}

const std::string& Configuration::get_title() const
{
    return _title;
}

const std::string& Configuration::get_version() const
{
    return _version;
}

const int& Configuration::get_window_position_x() const
{
    return _window_position_x;
}

const int& Configuration::get_window_position_y() const
{
    return _window_position_y;
}

const int& Configuration::get_resolution_width() const
{
    return _resolution_width;
}

 const int& Configuration::get_resolution_height() const
{
    return _resolution_height;
}

 const int& Configuration::get_refresh_rate() const
 {
     return _refresh_rate;
 }

 void Configuration::set_refresh_rate(const Uint8& refresh_rate)
 {
     _refresh_rate = refresh_rate;
 }
