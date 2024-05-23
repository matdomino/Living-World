#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(std::string givenOrganismId, World* givenWorld, std::unordered_map<std::string, Ancestor> givenAncestors)
		: Plant(4, givenOrganismId, givenWorld, givenAncestors, 2, 4) {}

	char getChar() {
		return 'D';
	}
};