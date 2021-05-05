#include "Texture.h"

Texture::Texture(const std::string& id, const std::string& path, SDL_Renderer* renderer)
    : Asset(id)
{
    // Load a bmp image to surface
    SDL_Surface* surface = nullptr;
    if (path.find("bmp") != std::string::npos)
    {
        surface = SDL_LoadBMP(path.c_str());
    }
    else if (path.find("png") != std::string::npos)
    {
        surface = IMG_Load(path.c_str());
    }
    else
    {
        std::cout << "Unknown image file extension. Path: " << path << std::endl;
    }
    Configuration::get_instance()->assertEX(surface, "Load an image file. Path: ", path.c_str());

    // Create a texture from surface
    _texture = SDL_CreateTextureFromSurface(renderer, surface);
    Configuration::get_instance()->assertEX(_texture, "Create a texture. Path:", path.c_str());

    // Get the number of pixels
    _pixel_width    = surface->w;
    _pixel_height   = surface->h;

    // Free an RGB surface
    SDL_FreeSurface(surface);
}

Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}

SDL_Texture* Texture::get_texture() const
{
    return _texture;
}

void Texture::render(SDL_Renderer* renderer, SDL_Rect* clip, SDL_Rect* destination, const SDL_RendererFlip& flip) const
{
    Configuration::get_instance()->assertEX(SDL_RenderCopyEx(renderer, _texture, clip, destination, 0, nullptr, flip),
        0,
        "Render a texture");
}
