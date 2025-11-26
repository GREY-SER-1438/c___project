#pragma once
#include "LocationBase.h"

class ServerRoom2Location : public LocationBase {
public:
    ServerRoom2Location(Game& game) : LocationBase(game) {}
    void run() override;
};
