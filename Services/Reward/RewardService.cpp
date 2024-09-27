
#include "IRewardService.h"
#include "../../Utils/List/IList.h"
#include "../../Utils/Rand/IRand.h"
#include "../../Entities/Item/IItem.h"
#include "../../Config/IConfig.h"

RewardService::RewardService() {}

List<Item> RewardService::RewardItem(int level)
{
    List<Item> rewardItems;

    int itemsQuantity = Rand::Randomize(0, Config::MaxRewards);

    for (int i = 0; i < itemsQuantity; i++)
    {
        int indexItem = Rand::Randomize(i, 49);

        Item item = Config::items[indexItem];
        item.SetLevel(level);

        rewardItems.Push(item);
    }

    return rewardItems;
}