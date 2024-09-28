#pragma once
#include <iostream>
#include <string>
#include "../BaseEntity/IBaseEntity.h"
#include "../Item/IItem.h"
#include "../../Utils/Stack/IStack.h"
#include "../../Utils/List/IList.h"
using namespace std;

class Player : public BaseEntity {
    public:
        string Name = "";
        int MaxHealth = 1000;
        int Health = 0;
        int Level = 1000;
        int Damage = 100;
        int BeltSlots = 10;
        List<Item> Belt;
        Stack<Item> Backpack;

        Player(string imageTextPath, List<Item> items);

        bool UseItem(Item item);
        bool GetItemToBelt();
        bool DiscardItemToBelt(int index);
        bool DiscardItemToBackpack();
        int GetMaxHealth();
        int GetDamage();
        int GetBeltSlotsQuantity();
        void HealLife(int quantity);
        void SetLevel(int level);
        int Atack(Player& enemy);
        void GenerateBonus(int bonus);
        void GenerateBonus();
};
