#pragma once

#include "Game_Object.h"

class Player : public Game_Object
{
public:
	Player(const std::string& id);
	~Player();

	// Inherited via Game_Object
	virtual void simulate_AI(const Uint32& milliseconds_to_simulate, Assets* assets, Input* input) override;
	virtual void render(const Uint32&, Assets* assets, SDL_Renderer* renderer) const override;

	const float& get_speed() const;
	void set_speed(const float& speed);

private:
	float _speed;
};

