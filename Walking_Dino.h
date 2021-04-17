#pragma once
#include "Game_Object.h"

class Walking_Dino : public Game_Object
{
public:
	Walking_Dino(const std::string& id);
	~Walking_Dino();

	// Inherited via Game_Object
	virtual void simulate_AI(const Uint32& milliseconds_to_simulate, Assets* assets, Input* input) override;
	virtual void render(const Uint32& milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer) const override;

private:
	

};

