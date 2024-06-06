#pragma once
#include "Organism.h"

class Animal : public Organism {
	protected:
		bool isHerbivorous;
		bool isCarnivorous;
		int hungerLevel;
		int fullHungerLevel;
	public:
		Animal(int givenLifeSpan, std::string givenOrganismId, std::list<Ancestor>* givenAncestors, int givenReproducePower, int givenPowerLimit, bool givenHerbStatus, bool givenCarnStatus, int givenFullHungerLevel)
			: Organism(givenLifeSpan, givenOrganismId, givenAncestors, givenReproducePower, givenPowerLimit), isHerbivorous(givenHerbStatus), isCarnivorous(givenCarnStatus), hungerLevel(givenFullHungerLevel), fullHungerLevel(givenFullHungerLevel) {}

		virtual char getChar() = 0;

		std::string getDetails() {
			return("Organism: " + this->organismId + "\n"
				+ "Power: " + std::to_string(this->power) + " (max: " + std::to_string(this->powerLimit) + ")" + "\n"
				+ "Minimal reproduce power level: " + std::to_string(this->reproducePower) + "\n"
				+ "Survived rounds: " + std::to_string(this->turnsSurvived) + " (lifespan: " + std::to_string(this->lifeSpan) + ")" + "\n"
				+ "Is herbivorous: " + std::to_string(this->isHerbivorous) + "\n"
				+ "Is carnivorous: " + std::to_string(this->isCarnivorous) + "\n"
				);
		}

		virtual bool getCarnivorousStatus() {
			return this->isCarnivorous;
		}

		virtual bool getHerbivorousStatus() {
			return this->isHerbivorous;
		}

		virtual void feed() {
			this->hungerLevel = this->fullHungerLevel;
		}

		virtual void live() {
			if (this->powerLimit > this->power && this->hungerLevel > 0) {
				power++;
			}

			if (this->turnsSurvived % 2 == 0 && this->hungerLevel > 0) {
				this->hungerLevel--;
			}

			this->turnsSurvived++;
		}
};