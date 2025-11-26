#include "StartLocation-1.h"
#include "Game.h"

void StartLocation::run() {
    // логика будет позже
    game.currentLocation = &game.workshopLocation; // Последняя строка, переставляющая указатель активной локации на следующую
}
