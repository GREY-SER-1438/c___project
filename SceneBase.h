#pragma once

class SceneBase {
public:
    Game &game;
    SceneBase(Game &g) : game(g) {}
    virtual ~SceneBase() {}
    virtual void run() = 0;
};