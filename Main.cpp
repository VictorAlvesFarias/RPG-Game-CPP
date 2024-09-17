#include <iostream>
#include <locale>
#include <vector>
#include "utils/List/List.cpp"
#include "Screens/StartingScreen.cpp"
#include "Entities/Enemy.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    bool end = false;
    int currentMenu = 1;
    StartingScreen startingScreen;
    Enemy enemy("Assets/Text-Images/Enemies/enemy-type-1.txt");

    while (!end)
    {
        switch (currentMenu)
        {
        case 1: //Starting
        {
            startingScreen.Render();
            startingScreen.Pause();
            startingScreen.Clear();
            currentMenu = 2;
        }
        break;
        case 2: //Figthing
        {
            enemy.RenderImageText();
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
