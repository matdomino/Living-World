#include <iostream>
#include "World.h"
#include <cstdlib>
#include <conio.h>
#include "Organism.h"
#include "Grass.h"
#include "Ancestor.h"
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

static void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void printWorld(const std::vector<std::vector<Organism*>>& map, int& turnNum) {
    std::cout << "| Turn number: " << turnNum << std::endl;

    std::cout << "+";
    for (size_t i = 0; i < map[0].size() * 2 + 1; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    for (size_t i = 0; i < map.size(); ++i) {
        std::cout << "| ";
        for (size_t j = 0; j < map[i].size(); ++j) {
            if (map[i][j] != nullptr) {
                std::cout << map[i][j]->getChar() << " ";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "+";
    for (size_t i = 0; i < map[0].size() * 2 + 1; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl << std::endl;
}

static void printAncestors (Organism* organism) {
    std::list<Ancestor> ancestors = organism->getAncestors();

    for (const Ancestor& ancestor : ancestors) {
        std::cout << "Organism ID: " << ancestor.organismId << std::endl;
        std::cout << "Birth Turn: " << ancestor.birthTurn << std::endl;
        std::cout << "Death Turn: " << ancestor.deathTurn << std::endl;
    }
}

static void printDetails(const std::list<Organism*>& organisms) {
    std::cout << std::endl << "| Choose organism: ";

    std::string input;
    std::getline(std::cin, input);

    int selected_index;
    try {
        selected_index = std::stoi(input);
    }
    catch (const std::exception& e) {
        selected_index = -1;
    }

    clearScreen();

    std::cout << "| Details:" << std::endl << std::endl;

    if (selected_index >= 0 && selected_index < organisms.size()) {
        auto it = organisms.begin();
        std::advance(it, selected_index);
        std::cout << (*it)->getDetails();
        
        std::cout << std::endl << "| Ancestors: " << std::endl;
        printAncestors(*it);
    }
    else {
        std::cout << "| Invalid option." << std::endl;
    }

    std::cout << std::endl << "| Press any key to return...";

    _getch();
}

static void printOrganisms(const std::list<Organism*>& organisms) {
    clearScreen();
    std::cout << "| Organisms: " << std::endl << std::endl;

    int index = 0;
    for (Organism* organism : organisms) {
        std::cout << index << ". " << organism->getId() << std::endl;
        index++;
    }

    printDetails(organisms);
}

int main()
{
    World world("world", 20, 20);

    while (true) {
        clearScreen();
        std::cout << "| Operations:   1. Simulate next turn.   2. Simulate next 10 turns.   3. Show organisms list.   4. Exit." << std::endl << std::endl;
        printWorld(world.getWorldMap(), world.getTurnNum());

        std::cout << "Option: ";
        char option = _getch();

        switch (option) {
        case '1':
            world.simulateTurn();
            break;
        case '2':
            for (int i = 0; i < 10; i++) {
                world.simulateTurn();
            };
            break;
        case '3':
            printOrganisms(world.getOrganisms());
            break;
        case '4':
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            break;
        };
    }
}
