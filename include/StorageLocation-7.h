#pragma once
#include "LocationBase.h"

class StorageLocation : public LocationBase {
public:
    StorageLocation(Game& game) : LocationBase(game) {}
    void run() override;
};
