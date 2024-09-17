#pragma once
#include <iostream>
#include <string>
#include "../Inventory/Inventory.cpp"
#include "../BaseEntity/IBaseEntity.h"

using namespace std;

class Player : public BaseEntity {
    public:
        Player(string imageTextPath);
        Player();

        string Name = "";
        int Health = 0;
        int Level = 0;
        int Damage = 0;
        Inventory Inventory;
};
