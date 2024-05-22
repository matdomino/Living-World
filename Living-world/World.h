#pragma once
#include <string>
#include <vector>

class Organism;

class World {
private:
	std::string worldName;
	int turnNum = 0;
	std::vector<std::vector<Organism*>> map;

public:
	World(std::string name, int sizeY, int sizeX) {
		this->worldName = name;
		this->map.resize(sizeY, std::vector<Organism*>(sizeX, nullptr));
	}

	std::vector<std::vector<Organism*>>& getWorldMap() {
		return this->map;
	}

	int& getTurnNum() {
		return this->turnNum;
	}

	void simulateTurn() {
		this->turnNum++;
	}
};
