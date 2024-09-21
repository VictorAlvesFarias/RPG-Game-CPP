 
#include "IReward.h"
#include "../Utils/List/IList.h"
#include "../Utils/Rand/IRand.h"
#include "../Entities/Item/IItem.h"
#include "../Config/IConfig.h"

 Reward::Reward()
{
}
List<Item> RewardItem(int level) {
    List<Item> rewardItems;
    int itemsQuantity = Rand::Randomize(1, 5);
    
    for (int i = 0; i < itemsQuantity; i++) {
        int indexItem = Rand::Randomize(0, 49); 
        Item item = Config::items[indexItem];

        rewardItems.Push(Config::items[indexItem]);
    }
    
    return rewardItems;
}
 