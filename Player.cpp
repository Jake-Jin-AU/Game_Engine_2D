#include "Player.h"

Player::Player(const std::string& id)
	: Game_Object(id, "Texture.Player.Idle", Layer::LAYER_3)
{
	// Transform
	_translation	= Vector_2D(50.f, 1950.f);
	_speed			= 0.1f;

	// Collider
	_collider.set_radius(_width / 5.f);
	_collider.set_translation(Vector_2D(_width / 2.f, _height - (_collider.get_radius() / 2.f)));

	// State
	_state.push(State::Idle);
}

Player::~Player()
{
}

void Player::simulate_AI(const Uint32&, Assets* assets, Input* input)
{
	switch (_state.top())
	{
	case State::Idle:
		if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::DOWN) && _velocity.calculate_magnitude() > 0.f)
		{
			push_state(State::Running, assets);
		}
		else if (_velocity.calculate_magnitude() > 0.f)
		{
			push_state(State::Walking, assets);
		}
		break;
	case State::Walking:
		if (_velocity.calculate_magnitude() == 0.f)
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::PRESSED))
		{
			push_state(State::Running, assets);
		}
		break;
	case State::Running:
		if (_velocity.calculate_magnitude() == 0.f)
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::RUNNING, Input::Button_State::RELEASED))
		{
			pop_state(assets);
		}
		break;
	}

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
	_velocity.set_scale(_speed);
}

void Player::render(const Uint32& milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, scene);
}

const float& Player::get_speed() const
{
	return _speed;
}

void Player::set_speed(const float& speed)
{
	_speed = speed;
}

void Player::push_state(const State& state, Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.push(state);
	handle_enter_state(_state.top(), assets);
	}

void Player::pop_state(Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.pop();
	handle_enter_state(_state.top(), assets);
}

void Player::handle_enter_state(const State& state, Assets* assets)
{
	switch (state)
	{
		case State::Idle:
		{
			_texture_id = "Texture.Player.Idle";
			break;
		}
		
		case State::Walking:
		{
			_texture_id = "Texture.Player.Walking";
			_speed = 0.15f;

			const int walking_channel = 1;
			Sound* sound = (Sound*)assets->get_asset("Sound.Effect.Walking");
			Mix_PlayChannel(walking_channel, sound->get_sound(), -1);
			break;
		}

		case State::Running:
		{
			_texture_id = "Texture.Player.Running";
			_speed = 0.3f;

			const int running_channel = 2;
			Sound* sound = (Sound*)assets->get_asset("Sound.Effect.Running");
			Mix_PlayChannel(running_channel, sound->get_sound(), -1);
			break;
		}
	}
}

void Player::handle_exit_state(const State& state, Assets*)
{
	switch (state)
	{
		case State::Idle:
		{
			break;
		}
			
		case State::Walking:
		{
			const int walking_channel = 1;
			Mix_HaltChannel(walking_channel);
			break;
		}

		case State::Running:
		{
			const int running_channel = 2;
			Mix_HaltChannel(running_channel);
			break;
		}
	}
}
