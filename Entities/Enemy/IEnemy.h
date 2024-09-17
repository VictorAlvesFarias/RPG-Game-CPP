#pragma once
#include <iostream>
#include <string>
#include "../Inventory/IInventory.h"
#include "../BaseEntity/IBaseEntity.h"

using namespace std;

class Enemy : public BaseEntity {
    public:
        Enemy(string imageTextPath);

        string Name;
        int Health;
        int Level;
        int Damage;
        Inventory Inventory;
};
