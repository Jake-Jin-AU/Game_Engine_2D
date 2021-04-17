#include "Game_Object.h"

Game_Object::Game_Object(const std::string& id, const std::string& texture_id, const Layer layer)
    : _translation(0, 0), _velocity(0, 0)
{
    _id         = id;
    _texture_id = texture_id;
    _layer      = layer;

    _width  = 100;
    _height = 100;
    _scale  = 1.f;

    _flip = SDL_RendererFlip::SDL_FLIP_NONE;
}

Game_Object::~Game_Object()
{
}

const std::string& Game_Object::get_id() const
{
    return _id;
}

const float& Game_Object::get_scale() const
{
    return _scale;
}

void Game_Object::set_scale(const float& scalar)
{
    _scale = scalar;
}

void Game_Object::simulate_physics(const Uint32& milliseconds_to_simulate, Assets*)
{
    Vector_2D velocity = _velocity;
    velocity.scale((float)milliseconds_to_simulate);

    _translation += velocity;
}

void Game_Object::render(const Uint32&, Assets* assets, SDL_Renderer* renderer) const
{
    

    SDL_Rect destination;
    destination.x   = (int)_translation.get_x();
    destination.y   = (int)_translation.get_y();
    destination.w   = _width;
    destination.h   = _height;
    
    Texture* texture = (Texture*)assets->get_asset(_texture_id);
    texture->render(renderer, nullptr, &destination, _flip);
}
