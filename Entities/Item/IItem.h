#pragma once
#include <iostream>
using namespace std;

class Item {

	public: Item(string name);
	public: Item();

	public: string Name;
	public: string Type;
	public: bool Consumable;
	public: int HealthRegen;	

};