#pragma once
#include "LocationBase.h"

// Подключаем все локации
#include "StartLocation-1.h"
#include "WorkshopLocation-2.h"
#include "ServerRoom1Location-3.h"
#include "ServerRoom2Location-4.h"
#include "FuelCompartment1Location-5.h"
#include "FuelCompartment2Location-6.h"
#include "StorageLocation-7.h"
#include "CoreLocation-8.h"

class Game {
public:
    // Каждая локация — как поле
    StartLocation startLocation;
    WorkshopLocation workshopLocation;
    ServerRoom1Location serverRoom1Location;
    ServerRoom2Location serverRoom2Location;
    FuelCompartment1Location fuelCompartment1Location;
    FuelCompartment2Location fuelCompartment2Location;
    StorageLocation storageLocation;
    CoreLocation coreLocation;

    // Указатель на текущую локацию
    LocationBase* currentLocation = nullptr;

    // Флаг завершения игры
    bool isRunning = true;

    Game();            // конструктор
    void loop();       // главный цикл игры
    void stop();       // остановка игры
};
