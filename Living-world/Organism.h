#pragma once
#include <vector>
#include <unordered_map>
#include "World.h"

class World;

struct Ancestor {
	int birthTurn;
	int deathTurn;
};

class Organism {
	protected:
		int turnsSurvived = 0;
		const int lifeSpan;
		const std::string organismId;
		World* world;
		std::unordered_map<std::string, Ancestor> ancestors;
		std::vector<Organism> descendants;
	public:
		Organism(int givenLifeSpan, std::string givenOrganismId, World* givenWorld, std::unordered_map<std::string, Ancestor> givenAncestors)
			: lifeSpan(givenLifeSpan), organismId(givenOrganismId), world(givenWorld), ancestors(givenAncestors) {};

		virtual char getChar() = 0;

		virtual void ancestorDied(const std::string& ancestorId, const int &turn) {
			this -> ancestors[ancestorId].deathTurn = turn;
		};

		virtual void die() {
			for (Organism& descendant : descendants) {
				descendant.ancestorDied(this->organismId, this->world->getTurnNum());
			}

			delete this;
		};
};