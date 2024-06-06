#pragma once

#include <vector>
#include <unordered_map>
#include "Ancestor.h"

class Organism {
	protected:
		int turnsSurvived = 0;
		const int lifeSpan;
		const std::string organismId;
		std::list<Ancestor>* ancestors;
	public:
		Organism(int givenLifeSpan, std::string givenOrganismId, std::list<Ancestor>* givenAncestors)
			: lifeSpan(givenLifeSpan), organismId(givenOrganismId), ancestors(givenAncestors) {};

		virtual char getChar() = 0;

		virtual std::string getDetails() = 0;

		virtual std::list<Ancestor>* getAncestors() {
			return this->ancestors;
		}

		virtual std::string getId() {
			return this->organismId;
		}

		virtual void live() = 0;

		virtual bool IsDying() = 0;

		virtual bool CanReproduce() = 0;

		virtual ~Organism() {
			// ZROBIC AKTUALIZACJE REKORDU W ANCESTORS
		}
};