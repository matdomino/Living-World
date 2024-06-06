#pragma once

class World;

#include <vector>
#include <unordered_map>
#include "Ancestor.h"

class Organism {
	protected:
		int turnsSurvived = 0;
		const int lifeSpan;
		const std::string organismId;
		World* world;
		std::list<Ancestor>* ancestors;
	public:
		Organism(int givenLifeSpan, std::string givenOrganismId, World* givenWorld, std::list<Ancestor>* givenAncestors)
			: lifeSpan(givenLifeSpan), organismId(givenOrganismId), world(givenWorld), ancestors(givenAncestors) {};

		virtual char getChar() = 0;

		virtual std::string getDetails() = 0;

		virtual std::list<Ancestor>* getAncestors() {
			return this->ancestors;
		}

		virtual std::string getId() {
			return this->organismId;
		}

		virtual void live() = 0;
};