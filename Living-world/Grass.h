#pragma once
#include "Plant.h"

class Grass : public Plant {
private:
	static int idCounter;
public:
	Grass(World* givenWorld, std::list<Ancestor> givenAncestors)
		: Plant(5, ("Grass" + std::to_string(++this->idCounter)), givenWorld, givenAncestors, 2, 3, false) {}

	char getChar() {
		return 'G';
	}
};

int Grass::idCounter = 0;