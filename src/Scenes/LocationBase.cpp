#include "LocationBase.h"
#include "Game.h"
#include <iostream>
using namespace std;

int LocationBase::ask(const initializer_list<int>& options) {
    string input;
    int value = 0;
    bool valid = false;

    while (!valid) {
        cout << "> ";
        cin >> input;

        // --- проверка на инвентарь ---
        if (input == "I" || input == "i") {
            game.showInventory();   // <-- вызываешь свою функцию
            continue;               // снова ждём ввод
        }

        // --- проверка: число ли это вообще ---
        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        if (!isNumber) {
            cout << "Введите число или I для инвентаря.\n";
            continue;
        }

        // --- теперь точно число ---
        value = stoi(input);

        // --- сравниваем с доступными вариантами ---
        for (int option : options) {
            if (value == option) {
                valid = true;
                break;
            }
        }

        if (!valid) {
            cout << "Некорректный ввод, попробуйте снова.\n";
        }
    }

    return value;
}

