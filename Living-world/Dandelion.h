#pragma once
#include "Plant.h"

class Dandelion : public Plant {
private:
	static int idCounter;
public:
	Dandelion(World* givenWorld, std::list<Ancestor>* givenAncestors)
		: Plant(4, ("Dandelion" + std::to_string(++this->idCounter)), givenWorld, givenAncestors, 2, 4, false) {}

	char getChar() {
		return 'D';
	}
};

int Dandelion::idCounter = 0;