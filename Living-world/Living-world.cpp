#include <iostream>
#include "World.h"
#include <cstdlib>
#include <conio.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

bool keyPressed() {
    #ifdef _WIN32
        return _kbhit();
    #else
        return kbhit();
    #endif
}

void sleep(int milliseconds) {
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        usleep(milliseconds * 1000);
    #endif
}

static void printWorld(const std::vector<std::vector<int>>& map, int& turnNum, int& speed) {
    std::cout << "| Simulation speed: " << speed << std::endl;
    std::cout << "| Turn number: " << turnNum << std::endl;

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
    int speed = 2000;

    while (true) {
        system("cls");
        std::cout << "| Operations:   1. SpeedUp   2. SlownDown   3. Exit" << std::endl << std::endl;
        printWorld(world.getWorldMap(), world.getTurnNum(), speed);

        if (keyPressed()) {
            char option = _getch();

            switch (option) {
            case '1':
                if (speed > 500) speed -= 250;
                break;
            case '2':
                speed += 250;
                break;
            case '3':
                std::cout << "Exiting." << std::endl;
                return 0;
            default:
                break;
            }
        }

        world.simulateTurn();
        sleep(speed);
    }
}
