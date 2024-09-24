#ifndef REWARD_H
#define REWARD_H
 
#include "../../Utils/List/IList.h"
#include "../../Entities/Item/IItem.h"

class Reward {
public:
    Reward();
    List<Item> RewardItem(int level);
};

#endif // REWARD_H

