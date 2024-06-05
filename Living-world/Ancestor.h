#pragma once
#include <string>

struct Ancestor {
	std::string organismId;
	int birthTurn;
	int deathTurn;

	Ancestor(const std::string& id, int birth, int death)
		: organismId(id), birthTurn(birth), deathTurn(death) {}
};