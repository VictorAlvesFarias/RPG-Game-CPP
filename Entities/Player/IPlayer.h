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
        int Health = 1000;
        int MaxHealth = 1000;
        int Level = 1000;
        int Damage = 0;
        int BeltSlots = 10;
        List<Item> Belt;
        List<Item> Backpack;

        bool UseItem(Item item);
        bool GetItemToBelt();
        bool DiscardItemToBelt(int index);
        bool DiscardItemToBackpack();
        int GetMaxHealth();
        int GetDamage();
        void HealLife(int quantity);
};
