#pragma once
#include <iostream>

#include "Game_Object.h"

class Dino : public Game_Object
{
public:
	Dino(const std::string& id, const Vector_2D& pos);
	~Dino();

	// Inherited via Game_Object
	virtual void simulate_AI(const Uint32& milliseconds_to_simulate, Assets* assets, Input* input) override;
};

