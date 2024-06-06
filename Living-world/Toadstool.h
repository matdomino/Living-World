#pragma once
#include "Plant.h"

class Toadstool : public Plant {
private:
	static int idCounter;
public:
	Toadstool(std::list<Ancestor>* givenAncestors)
		: Plant(12, ("Toadstool" + std::to_string(++this->idCounter)), givenAncestors, 6, 8, true) {}

	char getChar() {
		return 'T';
	}
};

int Toadstool::idCounter = 0;