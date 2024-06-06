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
				std::list<Ancestor>* newBloodLine = new std::list<Ancestor>();;

				Organism* newOrganism = new T(newBloodLine);

				newBloodLine->push_back(Ancestor(newOrganism->getId(), this->turnNum, -1));;

				this->map[y][x] = newOrganism;
				positions.insert(position);
				number--;
			}
		}
	}

	void spawnOrganisms(int dandelionNum, int grassNum, int toadstoolNum) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		std::unordered_set<int> positions;
		int sizeY = map.size();
		int sizeX = map[0].size();

		addOrganism<Grass>(dandelionNum, positions, sizeX, sizeY);
		addOrganism<Dandelion>(grassNum, positions, sizeX, sizeY);
		addOrganism<Toadstool>(toadstoolNum, positions, sizeX, sizeY);
	}

public:
	World(std::string name, int sizeY, int sizeX) {
		this->worldName = name;
		this->map.resize(sizeY, std::vector<Organism*>(sizeX, nullptr));
		this->spawnOrganisms(5, 5, 4);
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
		// sprawdzenie czy moze sie swtorzyc - jesli nie to nic
		// jesli tak to stworz obiekt na mapie i odejmij power
		// PRZEKAZAC ROWNIEZ BLOODLINE!

		std::vector<std::pair<int, int>> emptyPositions;
		std::vector<std::pair<int, int>> directions = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

		for (const auto& direction : directions) {
			int newY = y + direction.first;
			int newX = x + direction.second;

			if (newY >= 0 && newY < map.size() && newX >= 0 && newX < map[0].size() && map[newY][newX] == nullptr) {
				emptyPositions.push_back({ newY, newX });
			}
		}

		if (!emptyPositions.empty()) {
			std::pair<int, int> newPosition = emptyPositions[generateIndex(0, emptyPositions.size() - 1)];

			Organism* parent = map[y][x];
			std::list<Ancestor>* bloodLine = *parent->getBloodLine();

			// TU ZMIENIC ZEBY SPRAWDZALO JAKIEGO TYPU JEST parent i utworzylo nowy
			Organism* newOrganism = parent->clone(newBloodLine);

			bloodLine->push_back(Ancestor(newOrganism->getId(), this->turnNum, newOrganism->getId()));

			map[newPosition.first][newPosition.second] = newOrganism;

			// DODAC REDUKCJE POWER

		}
	}

	void simulateTurn() {
		this->turnNum++;
		std::vector<std::pair<int, int>> toDelete;

		for (int y = 0; y < map.size(); y++) {
			for (int x = 0; x < map[y].size(); x++) {
				Organism* organism = map[y][x];
				if (organism != nullptr) {
					if (organism->IsDying()) {
						toDelete.push_back({ y, x });
					} else {
						organism->live();

						if (organism->CanReproduce()) {
							// reproduce(y, x);
						}
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
