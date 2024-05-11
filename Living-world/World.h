#pragma once
#include <string>
#include <vector>

class World {
private:
	std::string worldName;
	int turnNum = 0;
	std::vector<std::vector<int>> map;

public:
	World(std::string name, int sizeY, int sizeX) {
		worldName = name;
		map.resize(sizeY, std::vector<int>(sizeX));
	}

	std::vector<std::vector<int>>& getWorldMap() {
		return map;
	}

	int& getTurnNum() {
		return turnNum;
	}

	void simulateTurn() {
		turnNum++;
	}
};