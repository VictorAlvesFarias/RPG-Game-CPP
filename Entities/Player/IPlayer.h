#pragma once
#include <iostream>
#include <string>
#include "../BaseEntity/IBaseEntity.h"
#include "../Item/IItem.h"
#include "../../Utils/List/IList.h"
using namespace std;

class Player : public BaseEntity {
    public:
        Player(string imageTextPath);
        Player();

        string Name = "";
        int Health = 0;
        int Level = 0;
        int Damage = 0;
        int BeltSlots = 0;
        List<Item> Belt;
        List<Item> Backpack;

        bool UseItem(Item item);
        bool GetItemToBackpack();
};
