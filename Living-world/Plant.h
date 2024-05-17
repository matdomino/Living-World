#pragma once
#include "Organism.h"

class Plant : public Organism {
	protected:
		int power;
		int reprducePower;
		int powerLimit;
	public:
		virtual void reproduce() {
			// ma byc tutaj sprawdzenie czy ma miejsce na paczkowanie
			// Losowanie miejsca gdzie sie stworzy nowy - tam gdzie mozna!!!!
		};

		virtual void live() {
			if (this->lifeSpan == this->turnsSurvived) {
				this->die();
			}

			if (this->power >= this->reprducePower) {
				this->reproduce();

				this->power -= this->reprducePower;
			}

			this->turnsSurvived++;
		};
};