#pragma once
#include <vector>

struct Ancestor {
	Organism ancestorRef;
	int birthTurn;
	int deathTurn;
};

class Organism {
	private:
		int power;
		int health;
		std::vector<Ancestor> ancestors;
		std::vector<Organism> descendants;
	public:
		Organism(int power, int health, std::vector<Ancestor> organismAncestors, std::vector<Organism> organismDescendants);
		Organism() : power(0), health(5), ancestors(std::vector<Ancestor>()), descendants(std::vector<Organism>()) {};

		void ancestorDied(Organism &ancestorRef, const int &turn) {
			for (Ancestor &ancestor : ancestors) {
				ancestor.deathTurn = turn;
			}
		};

		void die() {
			for (Organism &descendant : descendants) {
				descendant.ancestorDied(*this, 5); // ZMIENIC RUNDE LUB PO PROSTU WYWLOANIE ZMIENIC
			}
		}
};