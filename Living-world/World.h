#pragma once
#include <string>
#include <vector>
#include <ctime>

class Organism;

inline int generateIndex(int min, int max) {
	return min + rand() % (max - min + 1);
}

class World {
private:
	std::string worldName;
	int turnNum = 0;
	std::vector<std::vector<Organism*>> map;
	void spawnOrganisms() {
		std::srand(static_cast<unsigned int>(std::time(0)));

		int wylosowanaLiczba = generateIndex(0, 9);
	};

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
