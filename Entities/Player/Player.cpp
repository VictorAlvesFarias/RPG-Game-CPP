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

    Belt.ForEach([&](Item BeltItem, int index)
                 {
        if(item.Name == BeltItem.Name) {
            removeItemIndex = index;
        } });
    if (removeItemIndex > 0)
    {
        Belt.Delete(removeItemIndex);
        return true;
    }
    else
    {
        return false;
    }
}

int Player::GetMaxHealth() {
    int response = 0;

    Belt.ForEach([&response](Item item){ 
        if(item.Consumable == false){
            response += item.MaxHealth;
        }
    });

    return response; 
}

int Player::GetDamage() {
    int response = 0;

    Belt.ForEach([&response](Item item){ 
        if(item.Consumable == false){
            response += item.Damage;
        }
    });

    return response; 
}

void Player:: HealLife(int quantity) {
    if((Health + quantity) > MaxHealth ){
        Health = MaxHealth;
    }
    else {
        Health += quantity;
    }
}

bool Player::GetItemToBelt()
{
    if (!Backpack.IsEmpty())
    {
        Item item = Backpack.Get(Backpack.Size() - 1);

        if (Belt.Size() < BeltSlots)
        {
            Belt.Push(item);
            Backpack.Delete(Backpack.Size() - 1);

            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}