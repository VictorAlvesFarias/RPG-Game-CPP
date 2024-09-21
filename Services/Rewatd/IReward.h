#pragma once 
#include "../Utils/List/IList.h"
#include "../Utils/Rand/IRand.h"
#include "../Entities/Item/IItem.h"
#include "../Config/IConfig.h"
class Reward {
    public:Reward();

    public:List<Item> RewardItem(int level);
 
};
 
