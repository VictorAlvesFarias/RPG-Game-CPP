 
#include "IReward.h"
#include "../../Utils/List/IList.h"
#include "../../Utils/Rand/IRand.h"
#include "../../Entities/Item/IItem.h"
#include "../../Config/IConfig.h" 

Reward::Reward() { }

List<Item> Reward::RewardItem(int level) {
    List<Item> rewardItems;
    Rand rand;
    
    int itemsQuantity = rand.Randomize(0, 5);
    
    for (int i = 0; i < itemsQuantity; i++) { 
        int indexItem = rand.Randomize(i, 49);  
        
        Item item = Config::items[indexItem]; 
        
        rewardItems.Push(item);
    }
    
    return rewardItems;
}