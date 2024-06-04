#pragma once
#include "Plant.h"

class Toadstool : public Plant {
private:
	static int idCounter;
public:
	Toadstool(World* givenWorld, std::unordered_map<std::string, Ancestor> givenAncestors = std::unordered_map<std::string, Ancestor>())
		: Plant(12, ("Toadstool" + std::to_string(++this->idCounter)), givenWorld, givenAncestors, 4, 4, true) {}

	char getChar() {
		return 'T';
	}
};

int Toadstool::idCounter = 0;