#pragma once
#include "LocationBase.h"

class FuelCompartment1Location : public LocationBase {
public:
    FuelCompartment1Location(Game& game) : LocationBase(game) {}
    void run() override;

    bool foundSpacesuit = false;
    bool foundProtectionModule = false;
};
