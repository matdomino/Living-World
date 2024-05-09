#include <iostream>
#include "World.h"
#include <cstdlib>
#include <conio.h>

static void printWorld(std::vector<std::vector<int>>& map, int& turnNum) {
    std::cout << "| Turn number: " << turnNum << std::endl << std::endl;

    std::cout << "+";
    for (size_t i = 0; i < map[0].size() * 2 + 1; ++i) {
        std::cout << "-";
    }
    std::cout << "+" << std::endl;

    for (size_t i = 0; i < map.size(); ++i) {
        std::cout << "| ";
        for (size_t j = 0; j < map[i].size(); ++j) {
            std::cout << map[i][j] << " ";
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
    World world("world", 40, 80);
    while (true) {
        system("cls");
        printWorld(world.getWorldMap(), world.getTurnNum());
        std::cout << "| Operations: " << std::endl;
        std::cout << "| 1. Simulate next turn." << std::endl;
        std::cout << "| 2. Simulate next 10 turns." << std::endl;
        std::cout << "| 3. Exit." << std::endl;
        std::cout << "| Option: ";

        char option = _getch();

        switch (option) {
            case '1':
                // 1 TURA FUNKCJA
                std::cout << 1 << std::endl;
                break;
            case '2':
                // 10 TUR FUNKCJA
                std::cout << 10 << std::endl;
                break;
            case '3':
                std::cout << "Exiting." << std::endl;
                return 0;
            default:
                break;
        }
    }
}
