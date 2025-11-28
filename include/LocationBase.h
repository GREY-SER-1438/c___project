#pragma once
#include <iostream>

class Game;

class LocationBase {
protected:
    Game& game;
public:
    LocationBase(Game& g) : game(g) {}
    virtual void run() = 0;
    virtual ~LocationBase() = default;

    int readInt();
    int ask(const std::initializer_list<int>& options);
};
