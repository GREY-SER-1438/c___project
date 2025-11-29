#pragma once
#include "LocationBase.h"

class CoreLocation : public LocationBase {
public:
    CoreLocation(Game& game) : LocationBase(game) {}
    void run() override;

    void idealEnding();
    void twoItemsEnding(bool disk, bool catalyst, bool chip);
    void oneItemEnding(bool disk, bool catalyst, bool chip);
    void zeroItemsEnding();
};
