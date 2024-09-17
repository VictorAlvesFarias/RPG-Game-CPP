#include <iostream>
#include "BaseScreen.cpp" 
using namespace std;

class PlayerStatusScreen : public BaseScreen
{
    public:void RenderImageText(int health, int damage)
    {
        cout << "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"; 
        cout << "Life:" + health; 
        cout << "Damage:" + damage; 
    };
};
