#include "IPlayer.h"
#include "../Item/IItem.h"

Player::Player(string imageTextPath)
{
    ImageTextPath = imageTextPath;
}

Player::Player()
{
}

bool Player::UseItem(Item item)
{
    int removeItemIndex = -1;

    Backpack.ForEach([&](Item backpackItem, int index){
        if(item.Name == backpackItem.Name) {
            removeItemIndex = index;
        } }
    );
    if (removeItemIndex > 0)
    {
        Backpack.Delete(removeItemIndex);
        return true;
    }
    else
    {
        return false;
    }
}

bool Player::GetItemToBackpack()
{
    if (!Belt.IsEmpty())
    {
        Item item = Belt.Get(Belt.Size() - 1);

        if (Backpack.Size() < BeltSlots)
        {
            Backpack.Push(item);
            Belt.Delete(Belt.Size() - 1);

            return true;
        }
        return false; 
    }
    else
    {
        return false;
    }
}