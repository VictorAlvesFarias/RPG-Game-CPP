#include "BaseScreen/IBaseScreen.h"
#include "../Entities/Player/IPlayer.h"
#include "../Utils/String/IString.h"
using namespace std;

class PlayerStatusScreen : public BaseScreen
{
    public:void RenderImageText(Player& player)
    {
        String strExtension;
    
        cout << "-----------------------------PLAYER STATUS----------------------------------\n"; 
        cout << "- Life: " << strExtension.PadStart(player.Health, to_string(player.GetMaxHealth()).size(), '0') << '/' << player.GetMaxHealth()<< '\n';
        cout << "- Damage: " << player.GetDamage() << '\n'; 
        cout << "- Slots no cinto: " << player.BeltSlots  << '\n'; 
    };

        public:void RenderImageTextEnemy(Player& enemy)
    {
        String strExtension;
    
        cout << "-----------------------------ENEMY STATUS----------------------------------\n"; 
        cout << "- Life: " << strExtension.PadStart(enemy.EnemyHealth, to_string(enemy.GetMaxHealthEnemy()).size(), '0') << '/' << enemy.GetMaxHealthEnemy()<< '\n';
        cout << "- Damage: " << enemy.GetDamage() << '\n'; 
    };
};
