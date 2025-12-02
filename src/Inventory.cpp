#include "Inventory.h"

void Inventory::add(const string& id) {
    for (auto& item : items) {
        if (item.id == id) {
            item.obtained = true;
            return;
        }
    }
}

void Inventory::remove(const std::string& id) {
    for (auto& item : items) {
        if (item.id == id) {
            item.obtained = false;
            return;
        }
    }
}


void Inventory::show() {
    cout << "\n===== ИНВЕНТАРЬ =====\n";
    bool empty = true;

    for (auto& item : items) {
        if (item.obtained) {
            cout << "- " << item.display << "\n";
            empty = false;
        }
    }

    if (empty) cout << "(пусто)\n";
    cout << "=====================\n\n";
}
