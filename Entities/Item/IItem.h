#pragma once
#include <iostream>
using namespace std;

class Item {

	public: Item(string name, bool consumable, int healing, int maxHealth, int beltSlots, int damage);
	public: Item();

	public: string Name;
	public: bool Consumable;
	public: int Healing = 100;	
	public: int MaxHealth = 100;	
	public: int BeltSlots = 1;
	public: int Damage = 100;
	public: void GenerateBonus(Item item);
	public: void SetLevel(int level, Item item);

};