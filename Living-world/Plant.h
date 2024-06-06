#pragma once
#include "Organism.h"

class Plant : public Organism {
	protected:
		int power = 0;
		int reproducePower;
		int powerLimit; 
		const bool isPoisonous;
	public:
		Plant(int givenLifeSpan, std::string givenOrganismId, std::list<Ancestor>* givenAncestors, int givenReproducePower, int givenPowerLimit, bool givenPoisonousStatus)
			: Organism(givenLifeSpan, givenOrganismId, givenAncestors), reproducePower(givenReproducePower), powerLimit(givenPowerLimit), isPoisonous(givenPoisonousStatus) {}

		virtual char getChar() = 0;

		std::string getDetails() {
			return("Organism: " + this->organismId + "\n"
				+ "Power: " + std::to_string(this->power) + " (max: " + std::to_string(this->powerLimit) + ")" + "\n"
				+ "Minimal reproduce power level: " + std::to_string(this->reproducePower) + "\n"
				+ "Survived rounds: " + std::to_string(this->turnsSurvived) + " (lifespan: " + std::to_string(this->lifeSpan) + ")" + "\n"
				+ "Poisonous: " + std::to_string(this->isPoisonous) + "\n"
				);
		}

		virtual bool getPoisonousStatus() {
			return this->isPoisonous;
		}

		virtual bool IsDying() {
			if (this->lifeSpan == this->turnsSurvived) {
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

		virtual void live() {
			if (this->powerLimit > this->power) {
				power++;
			}

			this->turnsSurvived++;
		}

		virtual ~Plant() {}
};