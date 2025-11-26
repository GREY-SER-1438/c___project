#pragma once
#include "LocationBase.h"

class CoreLocation : public LocationBase {
public:
    CoreLocation(Game& game) : LocationBase(game) {}
    void run() override;
};
