#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
	Grass(std::string givenOrganismId, World* givenWorld, std::unordered_map<std::string, Ancestor> givenAncestors)
		: Plant(5, givenOrganismId, givenWorld, givenAncestors, 2, 3) {}

	char getChar() {
		return 'G';
	}
};