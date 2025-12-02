#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;

class Inventory {
public:
    vector<Item> items;

    void remove(const std::string& id);
    void add(const string& id);
    void show();
};