#include <iostream>
#include "Inventory.cpp" 
#include "BaseEntity.cpp" 
using namespace std;

class Player : public BaseEntity {
	public: Player(string imageTextPath){
		ImageTextPath = imageTextPath;
	}
	
	public: string Name;
	public: int Health;
	public: int Level;
	public: int Damage;
	public: Inventory Inventory;
};