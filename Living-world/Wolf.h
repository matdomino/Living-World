#pragma once
#include "Animal.h"

class Wolf : public Animal {
private:
	static int idCounter;
public:
	Wolf(std::list<Ancestor>* givenAncestors)
		: Animal(8, ("Wolf" + std::to_string(++this->idCounter)), givenAncestors, 4, 8, 0, 1, 6) {}

	char getChar() {
		return 'W';
	}
};

int Wolf::idCounter = 0;