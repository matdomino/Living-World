#include "Organism.h"
#include "World.h"

void Organism::die() {
    for (Organism& descendant : descendants) {
        descendant.ancestorDied(this->organismId, this->world->getTurnNum());
    }

    delete this;
}