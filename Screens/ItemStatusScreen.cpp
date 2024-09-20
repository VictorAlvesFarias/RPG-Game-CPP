#include "BaseScreen/IBaseScreen.h"
#include "../Entities/Item/IItem.h"
#include "../Utils/String/IString.h"
using namespace std;

class ItemStatusScreen : public BaseScreen
{
public:
    void RenderImageText(Item &item)
    {
        String strExtension;

        cout << "------------------------------ITEM STATUS-----------------------------------\n";
        if (item.Name != "")
        {
            cout << "-Nome do item: " << item.Name << '\n';
        }
        if (item.Damage != 0)
        {
            cout << "-Aumento de dano: " << item.Damage << '\n';
        }
        if (item.MaxHealth != 0)
        {
            cout << "-Aumento na vida maxima: " << item.MaxHealth << '\n';
        }
        if (item.Healing != 0)
        {
            cout << "-Cura ao usar:" << item.Healing ;
        }
    };
};
