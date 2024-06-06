#pragma once

#include <vector>
#include <unordered_map>
#include "Ancestor.h"

class Organism {
	protected:
		int turnsSurvived = 0;
		const int lifeSpan;
		const std::string organismId;
		int power = 0;
		int reproducePower;
		int powerLimit;
		std::list<Ancestor>* ancestors;
	public:
		Organism(int givenLifeSpan, std::string givenOrganismId, std::list<Ancestor>* givenAncestors, int givenReproducePower, int givenPowerLimit)
			: lifeSpan(givenLifeSpan), organismId(givenOrganismId), ancestors(givenAncestors), reproducePower(givenReproducePower), powerLimit(givenPowerLimit) {}

		virtual char getChar() = 0;

		virtual std::string getDetails() = 0;

		virtual std::list<Ancestor>* getAncestors() {
			return this->ancestors;
		}

		virtual std::string getId() {
			return this->organismId;
		}

		virtual void live() = 0;

		virtual bool IsDying(int turn) {
			if (this->lifeSpan == this->turnsSurvived) {

				for (auto& ancestor : *this->ancestors) {
					if (ancestor.organismId == this->organismId) {
						ancestor.deathTurn = turn;
						break;
					}
				}

				return true;
			}
			else {
				return false;
			}
		}

		virtual bool CanReproduce() {
			if (this->power >= this->reproducePower) {
				return true;
			}
			else {
				return false;
			}
		}

		virtual void reproduced() {
			this->power -= this->reproducePower;
		}

		virtual ~Organism() {}
};