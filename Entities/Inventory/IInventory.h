#pragma once
#include <iostream>
#include "../Item/IItem.h"
#include "../../Utils/List/IList.h"

using namespace std;

class Inventory {
    public:
        List<Item> Backpack;
        List<Item> Belt;
};
