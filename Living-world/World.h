#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <unordered_set>
#include "Grass.h"
#include "Dandelion.h"

class Organism;

inline int generateIndex(int min, int max) {
	return min + rand() % (max - min + 1);
}

class World {
private:
	std::string worldName;
	int turnNum = 0;
	std::vector<std::vector<Organism*>> map;

	template<class T>
	void addOrganism(int& number, std::unordered_set<int>& positions, int& sizeX, int& sizeY) {
		while (number > 0) {
			int y = generateIndex(0, sizeY - 1);
			int x = generateIndex(0, sizeX - 1);
			int position = y * sizeX + x;

			if (positions.find(position) == positions.end()) {
				this->map[y][x] = new T(this);
				positions.insert(position);
				number--;
			}
		}
	}

	void spawnOrganisms(int dandelionNum, int grassNum) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		std::unordered_set<int> positions;
		int sizeY = map.size();
		int sizeX = map[0].size();

		addOrganism<Grass>(dandelionNum, positions, sizeX, sizeY);
		addOrganism<Dandelion>(grassNum, positions, sizeX, sizeY);
	}

public:
	World(std::string name, int sizeY, int sizeX) {
		this->worldName = name;
		this->map.resize(sizeY, std::vector<Organism*>(sizeX, nullptr));
		this->spawnOrganisms(5, 5);
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
