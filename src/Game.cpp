#include <windows.h>
#include "Game.h"


Game::Game()
        : startLocation(*this),
          serverRoom1Location(*this),
          serverRoom2Location(*this),
          fuelCompartment1Location(*this),
          fuelCompartment2Location(*this),
          storageLocation(*this),
          coreLocation(*this)
{
    currentLocation = &startLocation; // начинаем со старта
    srand(static_cast<unsigned>(time(nullptr)));
}

void Game::loop() {
    while (isRunning && currentLocation != nullptr) {
        currentLocation->run();
    }
}

void Game::stop() {
    isRunning = false;
}

void Game::enableANSI()
    {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    }