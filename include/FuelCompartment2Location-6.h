#pragma once
#include "LocationBase.h"

class FuelCompartment2Location : public LocationBase {
public:
    FuelCompartment2Location(Game& game) : LocationBase(game) {}
    void run() override;
};
