#include "IItem.h"

Item::Item(string name, bool consumable, int healing, int maxHealth, int beltSlots, int damage)
{
	Name = name;
	Consumable = consumable;
	Healing = healing;
	MaxHealth = maxHealth;
	BeltSlots = beltSlots;
	Damage = damage;
}

Item::Item() { }

void SetLevel(int level, Item item){
	item.Healing += 2*level;
	item.MaxHealth += 2*level;
	item.Damage += 2*level;
}

void GenerateBonus(Item item){
    srand(static_cast<unsigned int>(time(0))); 
    int bonus = rand() % 10 + 1; 

    item.Damage += bonus;          
    item.Healing += bonus;     
    item.MaxHealth += bonus / 2; 
}