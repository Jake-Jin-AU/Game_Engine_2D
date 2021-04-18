#pragma once
#include <stack>

#include <SDL_mixer.h>

#include "Game_Object.h"
#include "assets.h"

class Player : public Game_Object
{
public:
	Player(const std::string& id);
	~Player();

	// Inherited via Game_Object
	virtual void simulate_AI(const Uint32& milliseconds_to_simulate, Assets* assets, Input* input) override;
	virtual void render(const Uint32&, Assets* assets, SDL_Renderer* renderer, Scene* scene) override;

	const float& get_speed() const;
	void set_speed(const float& speed);

	// State
	enum class State
	{
		Idle,
		Walking,
		Running
	};
	void push_state(const State& state, Assets* assets);
	void pop_state(Assets* assets);

private:
	void handle_enter_state(const State& state, Assets* assets);
	void handle_exit_state(const State& state, Assets* assets);

	float _speed;
	std::stack<State> _state;
};

