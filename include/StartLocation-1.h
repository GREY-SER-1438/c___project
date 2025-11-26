#pragma once
#include "LocationBase.h"

#pragma once
#include "LocationBase.h"

class StartLocation : public LocationBase {
public:
    StartLocation(Game& game) : LocationBase(game) {}
    void run() override;
};
