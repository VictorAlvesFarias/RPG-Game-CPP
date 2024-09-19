#include <iostream>
#include <locale>
#include <vector>
#include "utils/List/List.cpp"
#include "utils/String/String.cpp"
#include "Screens/BaseScreen/BaseScreen.cpp"
#include "Entities/BaseEntity/BaseEntity.cpp"
#include "Screens/StartingScreen.cpp"
#include "Screens/PlayerStatusScreen.cpp"
#include "Entities/Item/Item.cpp"
#include "Entities/Player/Player.cpp"
#include "Entities/Sqm/Sqm.cpp"
using namespace std;

string itemTypes[2] = { "weapon", "consumable" };

void InitPlayer(Player& player) {
    player.Backpack.Push(Item("Sword"));
    player.Backpack.Push(Item("Knife"));
    player.Backpack.Push(Item("Spear"));
    player.Belt.Push(Item("Regen Health Potion Large"));
    player.Belt.Push(Item("Regen Health Potion Small"));
    player.Belt.Push(Item("Regen Health Potion Middle"));
}

int main()
{
    bool end = false;
    int currentMenu = 6;

    StartingScreen startingScreen;
    PlayerStatusScreen playerStatusScreen;
    Player player;
    
    InitPlayer(player);

    while (!end)
    {
        if(currentMenu > 1) {
            playerStatusScreen.RenderImageText(player);
        }
        switch (currentMenu)
        {
        case 1: //Starting
        {
            startingScreen.RenderImageText();
            startingScreen.Pause();
            startingScreen.Clear();
            currentMenu = 2;
        }
        break;
        case 2: //Figthing
        {
        }
        break;
        case 3: //Reward
        {
        }
        break;
        case 4: //End Level
        {
        }
        break;
        case 5: //Cenary
        {
        }
        break;
        case 6: //Inventory
        {
            cout << "Backpack:\n";
            player.Backpack.ForEach([](Item item) {
                cout << "  -" + item.Name + "\n";
            });
            cout << "Belt:\n";
            player.Belt.ForEach([](Item item) {
                cout << "  -" + item.Name + "\n";
            });
            player.Pause();
        }
        break;
        default:
        {
            cout << "Opção inválida. Tente novamente." << endl;
        }
        break;
        }
    }

    return 0;
}
