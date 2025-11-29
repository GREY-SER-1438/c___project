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
