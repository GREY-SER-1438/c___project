#include "StartLocation-1.h"
#include "Game.h"
#include <iostream>
using namespace std;

void StartLocation::run() {
    cout << "\n--- СТАРТОВАЯ ЛОКАЦИЯ ---\n\n";

    cout <<
         "Вы приходите в себя в маленькой, полуразрушенной комнате.\n"
         "Мигающий свет плохо освещает стены. Нужно понять, что происходит.\n\n";

    // === Часть 1: Осмотр + Проверка дверей ===

    bool inspectedRoom = false;
    bool checkedDoors = false;

    while (!inspectedRoom || !checkedDoors) {

        cout << "Что сделать?\n";

        if (!inspectedRoom) cout << "1) Осмотреть комнату\n";
        if (!checkedDoors) cout << "2) Проверить двери\n";

        int choice;

        // Разрешены только те варианты, которые ещё НЕ сделаны
        if (!inspectedRoom && !checkedDoors)
            choice = ask({1, 2});
        else if (!inspectedRoom)
            choice = ask({1});
        else
            choice = ask({2});

        switch (choice) {
            case 1:
                cout <<
                     "\nВы внимательно изучаете помещение: полки, инструменты, обломки.\n"
                     "На столе разбросаны старые записки, но большинство не разобрать.\n\n";
                inspectedRoom = true;
                break;

            case 2:
                cout <<
                     "\nВы пробуете все двери. Большинство заблокировано.\n"
                     "Но одна дверь приоткрыта — она ведёт в мастерскую.\n\n";
                checkedDoors = true;
                break;
        }
    }

    // === Часть 2: Вход в мастерскую ===

    cout << "1) Войти в мастерскую\n";
// todo
    int a = ask({1,1488});     // единственный допустимый вариант = идеальная замена do/while
    if (a == 1488) {
        game.hasResearchDisk = true;
        game.catalystObtained = true;
        game.oxygenChipObtained = true;
        game.currentLocation = &game.coreLocation;
        return;
    }

    cout <<
         "\nВы осторожно заходите в мастерскую — помещение просторнее\n"
         "и выглядит более функциональным. На стенах закреплены инструменты.\n\n";


    // === Часть 3: взять фонарик или ПНВ ===

    bool tookFlashlight = false;
    bool tookNVG = false;

    cout << "На стене висят два предмета. Можно взять только один.\n";
    cout << "1) Фонарик\n";
    cout << "2) Прибор ночного видения\n";

    int itemChoice = ask({1, 2});

    if (itemChoice == 1) {
        cout << "\nВы берёте фонарик. Полезная вещь.\n\n";
        game.startLocation.tookFlashlight = true;
    } else {
        cout << "\nВы берёте ПНВ. Аккуратно надеваете на голову.\n\n";
        game.startLocation.tookNVG = true;
    }


    // === Часть 4: осмотр или уход ===

    cout <<
         "Что дальше?\n"
         "1) Продолжить осмотр мастерской\n"
         "2) Уйти\n";

    int workshopChoice = ask({1, 2});

    if (workshopChoice == 1) {
        cout <<
             "\nВы осматриваете помещение. В углу замечаете металлический лом.\n"
             "1) Взять лом\n"
             "2) Оставить\n";

        int crowbarChoice = ask({1, 2});

        if (crowbarChoice == 1) {
            cout << "\nВы забираете лом — пригодится.\n\n";
            game.startLocation.tookCrowbar = true;
        }
        else {
            cout << "\nВы решаете не брать лом.\n\n";
        }
    }

    // === Переход в следующую локацию ===

    cout <<
         "Вы покидаете мастерскую и направляетесь дальше по коридору...\n\n";
    game.currentLocation = &game.serverRoom1Location; // Последняя строка, переставляющая указатель активной локации на следующую
}
