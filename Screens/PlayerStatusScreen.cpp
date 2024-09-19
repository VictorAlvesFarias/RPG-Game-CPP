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
        cout << "- Life: " << strExtension.PadStart(player.Health, 4, '0') << '/' << strExtension.PadStart(player.GetMaxHealth(), 4, '0') << '\n';
        cout << "- Damage: " + strExtension.PadStart(player.GetDamage() ,4,'0') + '\n'; 
        cout << "- Slots no cinto: " << player.BeltSlots  << '\n'; 
    };
};
