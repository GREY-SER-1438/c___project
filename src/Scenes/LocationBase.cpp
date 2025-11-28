#include "LocationBase.h"
#include <iostream>
using namespace std;

int LocationBase::ask(const initializer_list<int>& options) {
    int value = 0;
    bool valid = false;

    while (!valid) {
        cout << "> ";
        value = readInt();   // <-- безопасный ввод числа

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

int LocationBase::readInt() {
    int value;
    cin >> value;

    while (cin.fail()) {           // если введена не цифра
        cin.clear();               // сбрасываем флаг ошибки
        cin.ignore(1000, '\n');    // очищаем буфер ввода

        cout << "Введите число.\n>";
        cin >> value;
    }

    return value;
}
