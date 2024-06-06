#pragma once
#include "Animal.h"

class Sheep : public Animal {
private:
	static int idCounter;
public:
	Sheep(std::list<Ancestor>* givenAncestors)
		: Animal(8, ("Sheep" + std::to_string(++this->idCounter)), givenAncestors, 4, 8, 1, 0, 6) {}

	char getChar() {
		return 'S';
	}
};

int Sheep::idCounter = 0;