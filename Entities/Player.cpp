#include <iostream>
#include "Inventory.cpp" 
#include "BaseEntity.cpp" 
using namespace std;

class Player : public BaseEntity {
	public: Player(string imageTextPath){
		ImageTextPath = imageTextPath;
	}
	public: Player(){
	}

	public: string Name = "";
	public: int Health = 0;
	public: int Level = 0;
	public: int Damage = 0;
	public: Inventory Inventory;
};