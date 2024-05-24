#include <iostream>
#include "World.h"
#include <cstdlib>
#include <conio.h>
#include "Organism.h"
#include "Grass.h"
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
            std::cout << "Ladna lista tu bedzie." << std::endl;
            break;
        case '4':
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            break;
        };
    }
}
