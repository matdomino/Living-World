#pragma once
#include "Organism.h"

class Plant : public Organism {
	protected:
		int power = 0;
		int reproducePower;
		int powerLimit;
	public:
		Plant(int givenLifeSpan, std::string givenOrganismId, World* givenWorld, std::unordered_map<std::string, Ancestor> givenAncestors, int givenReproducePower, int givenPowerLimit)
			: Organism(givenLifeSpan, givenOrganismId, givenWorld, givenAncestors), reproducePower(givenReproducePower), powerLimit(givenPowerLimit) {}

		virtual char getChar() = 0;

		virtual void reproduce() {
			// ma byc tutaj sprawdzenie czy ma miejsce na paczkowanie
			// Losowanie miejsca gdzie sie stworzy nowy - tam gdzie mozna!!!!

			return;
		};

		virtual void live() {
			if (this->lifeSpan == this->turnsSurvived) {
				this->die();
			}

			if (this->power >= this->reproducePower) {
				this->reproduce();

				this->power -= this->reproducePower;
			}

			if (this->powerLimit > this->power) {
				power++;
			}

			this->turnsSurvived++;
		};
};