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

Item::Item() {}

void Item::SetLevel(int level)
{
	Healing += 2 * level;
	MaxHealth += 2 * level;
	Damage += 2 * level;
}

void Item::GenerateBonus(int bonusChance)
{
	int bonus = rand() % bonusChance + 1;

	Damage += bonus;
	Healing += bonus;
	MaxHealth += bonus;
}

void Item::GenerateBonus()
{
	int bonus = rand() % Config::Bonus + 1;

	Damage += bonus;
	Healing += bonus;
	MaxHealth += bonus / 2;
}