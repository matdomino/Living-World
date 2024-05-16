#pragma once
#include "Organism.h"

class Plant : public Organism {
	private:
		int power;
		int powerLimit;
	public:
		virtual void live() {
			// sprawdzanie czy nie ma juz za duzego wieku - limitu wieku
			// inkrementacja power - jesli mozna
		};
		virtual void reproduce() {
			// ma byc tutaj sprawdzenie czy ma miejsce na paczkowanie
			// Losowanie miejsca gdzie sie stworzy nowy - tam gdzie mozna!!!!
		};
};