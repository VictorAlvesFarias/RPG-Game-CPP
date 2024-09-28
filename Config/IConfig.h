#pragma once
#include <iostream>
#include <fstream>
#include <string> 
#include "../Utils/List/IList.h"
#include "../Entities/Item/IItem.h"

class Config{
    public: const static int LevelBonusScaling = 2;
    public: const static int BattleChace = 50;
    public: const static int Bonus = 10;
    public: const static int MaxRewards = 10;
    public: const static int PlayerActions = 2;
    public: const static Item items[50];
};