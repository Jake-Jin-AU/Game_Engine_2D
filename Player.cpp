#include "Player.h"

Player::Player(const std::string& id, const Vector_2D& pos)
	: Game_Object(id, "Texture.Player.Idle", pos, Layer::LAYER_3), _jump_velocity(0.f, 0.f)
{
	// Transform
	//_translation	= Vector_2D(50.f, 200.f);
	_speed			= 0.05f;

	// Collider
	float radius = _width / 5.f;
	_circle_collider = new Circle_2D(radius, Vector_2D(_width / 2.f, _height - (radius / 2.f)));

	//_circle_collider.set_radius(_width / 5.f);
	//_collider.set_translation(Vector_2D(_width / 2.f, _height - (_collider.get_radius() / 2.f)));

	_is_affected_by_gravity = true;

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
		else if (input->is_button_state(Input::Button::JUMPING, Input::Button_State::PRESSED))
		{
			push_state(State::Jumping, assets);
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
		else if (input->is_button_state(Input::Button::JUMPING, Input::Button_State::PRESSED))
		{
			push_state(State::Jumping, assets);
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
		if (input->is_button_state(Input::Button::JUMPING, Input::Button_State::PRESSED))
		{
			push_state(State::Jumping, assets);
		}
		break;
	case State::Jumping:
		if (_velocity.calculate_magnitude() == 0.f)
		{
			pop_state(assets);
		}
		/*else if (input->is_button_state(Input::Button::JUMPING, Input::Button_State::RELEASED))
		{
			pop_state(assets);
		}*/
		else
		{
			if (_jump_velocity.get_y() < 0.f)
				_jump_velocity += Vector_2D(0.f, 0.5f);
			else
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

void Player::simulate_physics(const Uint32& milliseconds_to_simulate, Assets* assets, Scene* scene)
{
	// Jump
	_velocity += _jump_velocity;

	Game_Object::simulate_physics(milliseconds_to_simulate, assets, scene);
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
			_speed = 0.1f;

			const int walking_channel = 1;
			Sound* sound = (Sound*)assets->get_asset("Sound.Effect.Walking");
			Mix_PlayChannel(walking_channel, sound->get_sound(), -1);
			break;
		}

		case State::Running:
		{
			_texture_id = "Texture.Player.Running";
			_speed = 0.15f;

			const int running_channel = 2;
			Sound* sound = (Sound*)assets->get_asset("Sound.Effect.Running");
			Mix_PlayChannel(running_channel, sound->get_sound(), -1);
			break;
		}

		case State::Jumping:
		{
			_texture_id = "Texture.Player.Running";
			_jump_velocity = Vector_2D(0.f, -1.f);

			const int jumping_channel = 3;
			Sound* sound = (Sound*)assets->get_asset("Sound.Effect.Jumping");
			Mix_PlayChannel(jumping_channel, sound->get_sound(), -1);
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

		case State::Jumping:
		{
			const int jumping_channel = 3;
			Mix_HaltChannel(jumping_channel);
			break;
		}
	}
}
