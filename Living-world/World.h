#pragma once
#include <vector>
#include <ctime>
#include <unordered_set>
#include "Organism.h"
#include "Plant.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Toadstool.h"
#include "Ancestor.h"
#include "Animal.h"
#include "Sheep.h"
#include "Wolf.h"

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
				std::list<Ancestor>* newBloodLine = new std::list<Ancestor>();;

				Organism* newOrganism = new T(newBloodLine);

				newBloodLine->push_back(Ancestor(newOrganism->getId(), this->turnNum, -1));;

				this->map[y][x] = newOrganism;
				positions.insert(position);
				number--;
			}
		}
	}

	void spawnOrganisms(int dandelionNum, int grassNum, int toadstoolNum, int sheepNum, int wolfNum) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		std::unordered_set<int> positions;
		int sizeY = map.size();
		int sizeX = map[0].size();

		// addOrganism<Grass>(dandelionNum, positions, sizeX, sizeY);
		// addOrganism<Dandelion>(grassNum, positions, sizeX, sizeY);
		// addOrganism<Toadstool>(toadstoolNum, positions, sizeX, sizeY);
		// addOrganism<Sheep>(sheepNum, positions, sizeX, sizeY);
		addOrganism<Wolf>(wolfNum, positions, sizeX, sizeY);
	}

public:
	World(std::string name, int sizeY, int sizeX) {
		this->worldName = name;
		this->map.resize(sizeY, std::vector<Organism*>(sizeX, nullptr));
		this->spawnOrganisms(5, 5, 4, 30, 3);
	}

	std::vector<std::vector<Organism*>>& getWorldMap() {
		return this->map;
	}

	std::list<Organism*> getOrganisms() {
		std::list<Organism*> organisms;
		for (const auto& row : this->map) {
			for (Organism* organism : row) {
				if (organism != nullptr) {
					organisms.push_back(organism);
				}
			}
		}
		return organisms;
	}

	int& getTurnNum() {
		return this->turnNum;
	}

	void reproduce(int y, int x) {
		std::vector<std::pair<int, int>> emptyPositions;
		std::vector<std::pair<int, int>> directions = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

		Organism* parent = map[y][x];
		std::list<Ancestor>* bloodLine = parent->getAncestors();

		if (Animal* animal = dynamic_cast<Animal*>(parent)) {
			bool foundPartner = false;
			if (Sheep* sheep = dynamic_cast<Sheep*>(animal)) {
				for (const auto& direction : directions) {
					int newY = y + direction.first;
					int newX = x + direction.second;

					if (newY >= 0 && newY < map.size() && newX >= 0 && newX < map[0].size() && map[newY][newX] != nullptr) {
						if (Sheep* partner = dynamic_cast<Sheep*>(map[newY][newX])) {
							foundPartner = true;
							break;
						}
					}
				}
			}

			else if (Wolf* wolf = dynamic_cast<Wolf*>(animal)) {
				for (const auto& direction : directions) {
					int newY = y + direction.first;
					int newX = x + direction.second;

					if (newY >= 0 && newY < map.size() && newX >= 0 && newX < map[0].size() && map[newY][newX] != nullptr) {
						if (Wolf* partner = dynamic_cast<Wolf*>(map[newY][newX])) {
							foundPartner = true;
							break;
						}
					}
				}
			}

			if (foundPartner) {
				for (const auto& direction : directions) {
					int newY = y + direction.first;
					int newX = x + direction.second;

					if (newY >= 0 && newY < map.size() && newX >= 0 && newX < map[0].size() && map[newY][newX] == nullptr) {
						emptyPositions.push_back({ newY, newX });
					}
				}
			}
		}
		else {
			for (const auto& direction : directions) {
				int newY = y + direction.first;
				int newX = x + direction.second;

				if (newY >= 0 && newY < map.size() && newX >= 0 && newX < map[0].size() && map[newY][newX] == nullptr) {
					emptyPositions.push_back({ newY, newX });
				}
			}
		}

		if (!emptyPositions.empty()) {
			std::pair<int, int> newPosition = emptyPositions[generateIndex(0, emptyPositions.size() - 1)];

			Organism* newOrganism = nullptr;
			if (Grass* grass = dynamic_cast<Grass*>(parent)) {
				newOrganism = new Grass(bloodLine);
			}
			else if (Dandelion* dandelion = dynamic_cast<Dandelion*>(parent)) {
				newOrganism = new Dandelion(bloodLine);
			}
			else if (Toadstool* toadstool = dynamic_cast<Toadstool*>(parent)) {
				newOrganism = new Toadstool(bloodLine);
			}
			else if (Sheep* sheep = dynamic_cast<Sheep*>(parent)) {
				newOrganism = new Sheep(bloodLine);
			}
			else if (Wolf* wolf = dynamic_cast<Wolf*>(parent)) {
				newOrganism = new Wolf(bloodLine);
			}

			if (newOrganism != nullptr) {
				bloodLine->push_back(Ancestor(newOrganism->getId(), this->turnNum, -1));
				map[newPosition.first][newPosition.second] = newOrganism;
				parent->reproduced();
			}
		}
	}

	void simulateTurn() {
		this->turnNum++;
		std::vector<std::pair<int, int>> toDelete;

		for (int y = 0; y < map.size(); y++) {
			for (int x = 0; x < map[y].size(); x++) {
				Organism* organism = map[y][x];
				if (organism != nullptr) {
					if (organism->IsDying(this->turnNum)) {
						toDelete.push_back({ y, x });
					} else {
						if (organism->CanReproduce()) {
							reproduce(y, x);
						}

						organism->live();
					}
				}
			}
		}

		for (const auto& coord : toDelete) {
			int y = coord.first;
			int x = coord.second;
			delete map[y][x];
			map[y][x] = nullptr;
		}
	}
};
