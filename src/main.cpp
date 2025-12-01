#include <windows.h>
#include "Game.h"


int main() {
    Game game;
    game.enableANSI();
    game.loop();      // запуск главного игрового цикла
    return 0;
}
