#pragma once
#include "LocationBase.h"

class FuelCompartment1Location : public LocationBase {
public:
    FuelCompartment1Location(Game& game) : LocationBase(game) {}
    void run() override;

    // Предметы этой всего fuelCompartment
    bool foundSpacesuit = false;
    bool foundProtectionModule = false;
};
