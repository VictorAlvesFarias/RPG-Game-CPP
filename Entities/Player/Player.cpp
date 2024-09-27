#include "IPlayer.h"
#include "../Item/IItem.h"
#include "../../Config/IConfig.h"
#include "../../Utils/Stack/IStack.h"

Player::Player(string imageTextPath, List<Item> items)
{
    ImageTextPath = imageTextPath;
    items.ForEach([this](Item item, int index)
                  { Backpack.Push(item); });
    Damage = GetDamage();
    Health = GetMaxHealth();
}

bool Player::UseItem(Item item)
{
    int removeItemIndex = -1;

    Belt.ForEach([&](Item BeltItem, int index)
                 {
        if(item.Name == BeltItem.Name) {
            removeItemIndex = index;
            HealLife(item.Healing);
        } });
    if (removeItemIndex > -1)
    {
        Belt.Delete(removeItemIndex);
        return true;
    }
    else
    {
        return false;
    }
}

int Player::GetMaxHealth()
{
    int response = MaxHealth;

    Belt.ForEach([&response](Item item)
                 { 
        if(item.Consumable == false){
            response += item.MaxHealth;
        } });

    return response;
}

int Player::GetDamage()
{
    int response = Damage;

    Belt.ForEach([&response](Item item)
                 { 
        if(item.Consumable == false){
            response += item.Damage;
        } });

    return response;
}

void Player::HealLife(int quantity)
{
    if ((Health + quantity) > MaxHealth)
    {
        Health = MaxHealth;
    }
    else
    {
        Health += quantity;
    }
}

bool Player::GetItemToBelt()
{
    if (!Backpack.IsEmpty())
    {
        ;

        if (Belt.Size() < BeltSlots)
        {

            Item item = Backpack.Pop();
            Belt.Push(item);

            return true;
        }

        return false;
    }
    else
    {
        return false;
    }
}

int Player::GetBeltSlotsQuantity()
{
    int response = BeltSlots;

    Belt.ForEach([&response](Item item)
                 { 
        if(item.Consumable == false){
            response += item.BeltSlots;
        } });

    return response;
};

void Player::SetLevel(int level)
{
    Health += 2 * level;
    Damage += 2 * level;
}

int Player::Atack(Player &enemy)
{
    int damage = GetDamage();
    enemy.Health -= damage;
    return damage;
}

void Player::GenerateBonus(int bonusPercentage)
{
    int bonus = rand() % bonusPercentage + 1;

    Health += bonus;
    Damage += bonus;
}

void Player::GenerateBonus()
{
    int bonus = rand() % Config::Bonus + 1;

    MaxHealth += bonus;
    Damage += bonus;
}
