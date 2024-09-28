#include "BaseScreen/IBaseScreen.h"
#include "../Entities/Player/IPlayer.h"
#include "../Utils/String/IString.h"
using namespace std;

class EnemyStatusScreen : public BaseScreen
{
public:
    void RenderImageText(Player &enemy)
    {
        String strExtension;
        cout << "------------------------------ENEMY STATUS----------------------------------\n";
        cout << "- Life: " << strExtension.PadStart(enemy.Health, to_string(enemy.Health).size(), '0') << '/' << enemy.GetMaxHealth() << '\n';
        cout << "- Damage: " << enemy.GetDamage() << '\n';
        cout << "----------------------------------------------------------------------------\n";
    };
};
