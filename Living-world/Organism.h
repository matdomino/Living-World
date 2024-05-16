#pragma once
#include <vector>
#include <unordered_map>
#include "World.h"

struct Ancestor {
	int birthTurn;
	int deathTurn;
};

class Organism {
	private:
		int turnsSurvived;
		int lifeSpan;
		std::string organismId;
		World world;
		std::unordered_map<std::string, Ancestor> ancestors;
		std::vector<Organism> descendants;
	public:
		virtual void ancestorDied(const std::string& ancestorId, const int &turn) {
			this -> ancestors[ancestorId].deathTurn = turn;
		};

		virtual void die() {
			for (Organism& descendant : descendants) {
				descendant.ancestorDied(this->organismId, world.getTurnNum());
			}

			delete this;
		};
};