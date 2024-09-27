#include "IPlayer.h"
#include "../Item/IItem.h" 
#include "../../Utils/Stack/IStack.h"
#include "../../Services/Reward/IReward.h"

Player::Player(string imageTextPath)
{
    ImageTextPath = imageTextPath;
    InitPlayer(Backpack, 1);
}

Player::Player(int health, int damage, string imageTextPath){
    EnemyHealth = health;
    EnemyDamage = damage;
    ImageTextPath = imageTextPath; 

}

Player::Player(int health, int damage) {
    EnemyHealth = health;
    EnemyMaxHealth = health;
    EnemyDamage = damage;
}

Player::Player()
{
}

void Player::InitPlayer(Stack<Item>& backpack, int level) {
    Reward reward;
    List<Item> items = reward.RewardItem(level);

    items.ForEach([&backpack](Item item, int index){
        backpack.Push(item); 
    });

}

bool Player::UseItem(Item item)
{
    int removeItemIndex = -1;

    Belt.ForEach([&](Item BeltItem, int index){
        if(item.Name == BeltItem.Name) {
            removeItemIndex = index;
            HealLife(item.Healing);
        } 
    });
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

int Player::GetMaxHealth() {
    int response = MaxHealth;

    Belt.ForEach([&response](Item item){ 
        if(item.Consumable == false){
            response += item.MaxHealth;
        }
    });

    return response; 
}

int Player::GetMaxHealthEnemy() {
    return EnemyMaxHealth; 
}

int Player::GetHealthEnemy(){
    return EnemyHealth;
}

int Player::GetDamageEnemy() {
    return EnemyDamage;
}

int Player::GetDamage() {
    int response = Damage;

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

void Player:: HealLifeEnemy(int quantity) {
    cout << "O inimigo se curou em:" << quantity << endl;
    if((EnemyHealth + quantity) > EnemyMaxHealth ){
        EnemyHealth = MaxHealth;
    }
    else {
       EnemyHealth += quantity;
    }
}

bool Player::GetItemToBelt()
{
    if (!Backpack.IsEmpty())
    {;

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

void Player::SetLevel(int level, Player player) {
    cout << "entrou setlevel" << endl;

    player.Health += 2*level;
    player.Damage += 2*level;
        cout << "saindo setlevel" << endl;

}

void Player::Atack(Player& enemy) {
    cout << "Você atacou o inimigo e causou: " << Damage << " de dano" << endl;
    enemy.EnemyHealth -= Damage;
    cout << "O inimigo agora tem: " << enemy.EnemyHealth  << " pontos de vida" << endl;

}

void Player::AtackAsEnemy(Player& player) {
    cout << "O inimigo atacou e causou: " << EnemyDamage << " de dano" << endl;
    player.Health -= EnemyDamage;
    cout << "O Heroi agora tem: " << player.Health  << " pontos de vida" << endl;
}

void Player::Defend(){
    cout << "O heroi conseguiu defender o ataque!" << endl;
}

void Player::GenerateBonus(Player& entitie) {
   int bonus = rand() % 10 + 1; 

   entitie.Health += bonus;
   entitie.Damage += bonus;
   entitie.EnemyHealth += bonus;
   entitie.EnemyDamage += bonus;
}
