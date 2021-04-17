#include "Player.h"

Player::Player(const std::string& id)
	: Game_Object(id, "Texture.Player.Walking", Layer::LAYER_3)
{
	_translation	= Vector_2D(350.f, 350.f);
	_speed			= 0.1f;
}

Player::~Player()
{
}

void Player::simulate_AI(const Uint32&, Assets*, Input* input)
{
	_velocity = Vector_2D(0.f, 0.f);

	if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(1.f, 0);
	}

	if (input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(-1.f, 0);
	}

	if (input->is_button_state(Input::Button::UP, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, -1.f);
	}

	if (input->is_button_state(Input::Button::DOWN, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, 1.f);
	}

	_velocity.normalise();
	_velocity.scale(_speed);
}

void Player::render(const Uint32& milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer) const
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer);
}

const float& Player::get_speed() const
{
	return _speed;
}

void Player::set_speed(const float& speed)
{
	_speed = speed;
}
