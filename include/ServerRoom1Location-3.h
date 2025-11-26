#pragma once
#include "LocationBase.h"

class ServerRoom1Location : public LocationBase {
public:
    ServerRoom1Location(Game& game) : LocationBase(game) {}
    void run() override;
};
