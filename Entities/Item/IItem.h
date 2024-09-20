#pragma once
#include <iostream>
using namespace std;

class Item {

	public: Item(string name, bool consumable);
	public: Item();

	public: string Name;
	public: bool Consumable;
	public: int Healing = 100;	
	public: int MaxHealth = 100;	
	public: int BeltSlots = 1;
	public: int Damage = 100;
};