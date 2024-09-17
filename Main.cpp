#include <iostream>
#include <locale>
#include <vector>
#include "utils/List/List.cpp"
#include "utils/String/String.cpp"
#include "Screens/BaseScreen/BaseScreen.cpp"
#include "Screens/StartingScreen.cpp"
#include "Screens/PlayerStatusScreen.cpp"
#include "Entities/BaseEntity/BaseEntity.cpp"
#include "Entities/Enemy/Enemy.cpp"
#include "Entities/Player/Player.cpp"
#include "Entities/Sqm/Sqm.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    bool end = false;
    int currentMenu = 1;
    StartingScreen startingScreen;
    PlayerStatusScreen playerStatusScreen;
    Player player;
    Enemy enemy("Assets/Text-Images/Enemies/enemy-type-1.txt");

    while (!end)
    {
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
            enemy.RenderImageText();
            playerStatusScreen.RenderImageText(player);
            enemy.Pause();
            cout << "Menu" << endl;
        }
        break;
        case 3: //Reward
        {
            cout << "Game" << endl;
        }
        break;
        case 4: //End Level
        {
            cout << "Player status" << endl;
        }
        break;
        case 5: //Cenary
        {
            cout << "Inventory" << endl;
        }
        break;
        case 6: //Backpack and Gordel
        {
            cout << "Inventory" << endl;
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
