#pragma once
#include <iostream>
using namespace std;
#include "LocationBase.h"

#include "Inventory.h"
#include "StartLocation-1.h"
#include "ServerRoom1Location-3.h"
#include "ServerRoom2Location-4.h"
#include "FuelCompartment1Location-5.h"
#include "FuelCompartment2Location-6.h"
#include "StorageLocation-7.h"
#include "CoreLocation-8.h"

class Game {
public:
    // Все локации
    StartLocation startLocation;
    ServerRoom1Location serverRoom1Location;
    ServerRoom2Location serverRoom2Location;
    FuelCompartment1Location fuelCompartment1Location;
    FuelCompartment2Location fuelCompartment2Location;
    StorageLocation storageLocation;
    CoreLocation coreLocation;

    Inventory inventory;

    // Указатель на текущую локацию
    LocationBase* currentLocation = nullptr;

    // Флаг завершения игры
    bool isRunning = true;

    // Обязательные предметы
    bool hasResearchDisk = false;
    bool catalystObtained = false;
    bool oxygenChipObtained = false;

    void showInventory();

    void enableANSI(); // Для цветного текста

    Game();
    void loop();       // главный цикл игры
    void stop();
};
