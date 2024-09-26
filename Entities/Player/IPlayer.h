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
        Player(string imageTextPath);
        Player(int health, int damage, string imageTextPath);
        Player(int health, int damage);
        Player();

        string Name = "";
        int Health = 100;
        int EnemyHealth;
        int MaxHealth = 1000;
        int EnemyMaxHealth;
        int Level = 1000;
        int Damage = 10;
        int EnemyDamage = 5;
        int BeltSlots = 10;
        List<Item> Belt;
        Stack<Item> Backpack;

        bool UseItem(Item item);
        bool GetItemToBelt();
        bool DiscardItemToBelt(int index);
        bool DiscardItemToBackpack();
        int GetMaxHealth();
        int GetMaxHealthEnemy();
        int GetHealthEnemy();
        int GetDamage();
        int GetDamageEnemy();
        void HealLife(int quantity);
        void HealLifeEnemy(int quantity);
        void SetLevel(int level, Player player);
        void Atack(Player& enemy);
        void AtackAsEnemy(Player& player);
        void Defend();
        void GenerateBonus(Player& entitie);
        void InitPlayer(Stack<Item> &backpack, int level);
};
