#pragma once
#include "Organism.h"

class Plant : public Organism {
	protected:
		int power = 0;
		int reproducePower;
		int powerLimit; 
		const bool isPoisonous;
	public:
		Plant(int givenLifeSpan, std::string givenOrganismId, World* givenWorld, std::list<Ancestor>* givenAncestors, int givenReproducePower, int givenPowerLimit, bool givenPoisonousStatus)
			: Organism(givenLifeSpan, givenOrganismId, givenWorld, givenAncestors), reproducePower(givenReproducePower), powerLimit(givenPowerLimit), isPoisonous(givenPoisonousStatus) {}

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

		virtual void reproduce() {
			// ma byc tutaj sprawdzenie czy ma miejsce na paczkowanie
			// Losowanie miejsca gdzie sie stworzy nowy - tam gdzie mozna!!!!

			return;
		};

		virtual void die() {
			delete this;

			// dodac aktualizacje Ancestora
		}

		virtual void live() {
			if (this->lifeSpan == this->turnsSurvived) {
				this->world->removeOrganism(this);
				this->die();
			}

			if (this->power >= this->reproducePower) {
				this->reproduce();
			}

			if (this->powerLimit > this->power) {
				power++;
			}

			this->turnsSurvived++;
		};

		virtual ~Plant() {}
};