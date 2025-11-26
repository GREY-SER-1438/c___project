#pragma once
#include "LocationBase.h"

class WorkshopLocation : public LocationBase {
public:
    WorkshopLocation(Game& game) : LocationBase(game) {}
    void run() override;
};
