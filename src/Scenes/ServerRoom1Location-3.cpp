#include "ServerRoom1Location-3.h"
#include "Game.h"
#include <iostream>
using namespace std;

void ServerRoom1Location::run() {
    cout << "Вы входите в серверную. Тишина, но она напряжённая. Свет моргает.\n";

    // --- ВЫБОР 1: включать терминал или нет ---
    cout << "\n1) Включить терминал\n";
    cout << "2) Не осматривать\n";
    cout << "Ваш выбор: ";

    int terminalChoice = ask({1,2});

    if (terminalChoice == 1) {
        usedTerminal = true;
        cout << "\nТерминал включён...\n";
        cout << "Охлаждение: НЕИСПРАВНО\n";
        cout << "Диаграммы сети отображены.\n";
        cout << "ПРЕДУПРЕЖДЕНИЕ: перегрев внутренней секции!\n";
    } else {
        cout << "\nВы решаете не включать терминал.\n";
    }

    // --- ВЫБОР 2: осмотреть стойки (единственный вариант) ---
    cout << "\n1) Осмотреть стойки\n";
    cout << "Ваш выбор: ";

    int rackChoice = ask({1});

    cout << "\nВы находите предметы:\n";
    cout << "- Охлаждающий модуль\n";
    cout << "- Сломанный дисплей\n";
    cout << "- Клавиатура\n";

    if (usedTerminal) {
        cout << "\nПодсказка: охлаждающий модуль помог бы устранить перегрев.\n";
    }

    // --- ВЫБОР 3: что взять ---

    cout << "\nЧто взять?\n";
    cout << "1) Охлаждающий модуль\n";
    cout << "2) Сломанный дисплей\n";
    cout << "3) Клавиатура\n";
    cout << "4) Ничего\n";
    cout << "Ваш выбор: ";

    int itemChoice = ask({1,2,3,4});

    switch (itemChoice) {
        case 1:
            foundCoolingModule = true;
            cout << "Вы взяли охлаждающий модуль.\n";
            break;
        case 2:
            cout << "Вы взяли сломанный дисплей.\n";
            break;
        case 3:
            cout << "Вы взяли клавиатуру.\n";
            break;
        case 4:
            cout << "Вы решаете ничего не брать.\n";
            break;
    }

    // --- ВЫБОР 4: сенсорная дверь ---
    cout << "\nПеред вами сенсорный замок в другую секцию.\n";
    cout << "Открывать быстро — опасно, но экономит время.\n";

    cout << "\n1) Действовать быстро\n";
    cout << "2) Поискать код на одном из серверов\n";
    cout << "Ваш выбор: ";

    int doorChoice = ask({1,2});

    if (doorChoice == 1) {
        cout << "\nВы действуете быстро...\n";
        cout << "Короткое замыкание! Сервера сгорают.\n";
        cout << "Диск с исследовательскими данными теперь не получить.\n";
        game.currentLocation = &game.fuelCompartment1Location;
        return;
    }

    cout << "\nВы ищете код...\n";
    cout << "На одном из серверов найден рабочий блок.\n";
    cout << "Дверь открыта.\n";
    // логика будет позже
    game.currentLocation = &game.serverRoom2Location;
}
