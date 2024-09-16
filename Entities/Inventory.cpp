#include <iostream>
#include "Item.cpp" 
#include "Utils/List/List.cpp"
using namespace std;

class Inventory {
    public: List<Item> Backpack;
    public: List<Item> Belt;
};