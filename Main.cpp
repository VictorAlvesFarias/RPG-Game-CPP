#include <iostream>
#include <locale>
#include "utils/List/List.cpp"
#include "utils/Essentials/Essentials.cpp"
#include "Config/Config.cpp"
#include "utils/Rand/Rand.cpp"
#include "utils/Stack/Stack.cpp"
#include "utils/String/String.cpp"
#include "Screens/BaseScreen/BaseScreen.cpp"
#include "Entities/BaseEntity/BaseEntity.cpp"
#include "Screens/StartingScreen.cpp"
#include "Screens/PlayerStatusScreen.cpp"
#include "Screens/ItemStatusScreen.cpp"
#include "Entities/Item/Item.cpp"
#include "Entities/Player/Player.cpp"
#include "Entities/Sqm/Sqm.cpp"
#include "Services/Reward/Reward.cpp"

using namespace std;

int main()
{
    int level = 1;
    bool end = false;
    int currentMenu = 1;

    StartingScreen startingScreen;
    PlayerStatusScreen playerStatusScreen;
    ItemStatusScreen itemStatusScreen;
    Player player("Assets/Text-Images/Player/player.txt");

    while (!end)
    {
        switch (currentMenu)
        {
        case 1: // Starting
        {
            Essentials::Clear();
            startingScreen.RenderImageText();
            bool mainMenuIsOpen = true;
            int mainMenu;
            string options[2] = {
                "Ver inventário\n", 
                "Continuar\n",
            };

            while(mainMenuIsOpen){
                cout << "\n   Comandos:\n";
                for (size_t i = 0; i < 2; i++)
                {
                    cout << "   - " << i << " " << options[i];
                }

                Essentials::Command<int>("\n- Opcao: ", mainMenu);
                mainMenuIsOpen = false;
            }

            switch (mainMenu)
            {
                case 0: // Add reward to backpack
                {
                    currentMenu = 6;
                    continue;
                }
                case 1:
                {
                    currentMenu = 2;
                    continue;
                }
            } 
            
            Essentials::Pause(); 
        }
        break;

        case 2: // Figthing
        {
            Essentials::Pause();
        }
        break;

        case 3: // Reward
        {
            Reward reward;
            List<Item> items = reward.RewardItem(5);
            int rewardMenu = -1;
            int selectedItem = -1;
            bool rewardIsOpen = true;

            string options[8] = {
                "Colocar recompensa na mochila\n",
                "Colocar recompensa no cinto\n",
                "Descartar item da mochila\n",
                "Descartar item do cinto\n",
                "Enviar item para o cinto\n",
                "Ver item da recompensa detalhadamente\n",
                "Ver item do cinto detalhadamente\n",
                "Continuar\n",
            };

            while (rewardIsOpen)
            {
                Essentials::Clear();
                Essentials::RenderImageText("Assets/Text-Images/Mis/coin.txt");

                if (items.Size() == 0)
                {
                    cout << "Ops, Você nao encontrou nenhum item.\n";
                    Essentials::Pause();
                    rewardIsOpen = false;
                    break;
                }

                cout << "\n- Inventario:\n";
                cout << "\n   Mochila:\n";

                cout << "    - Quantidade de itens na mochila: " << player.Backpack.Size();
                cout << "\n";

                cout << "\n   Cinto:\n";

                if (player.Belt.Size() == 0)
                {
                    cout << "    - Sem nenhum item\n";
                }

                player.Belt.ForEach([](Item item, int index)
                                    { cout << "    - " + to_string(index) + " " + item.Name + "\n"; });

                cout << "\n   Itens ganhados:\n";
                items.ForEach([](Item item, int index)
                              { cout << "    - " + to_string(index) + " " + item.Name + "\n"; });

                if (rewardMenu == -1 && selectedItem == -1)
                {
                    cout << "\n   Comandos:\n";
                    for (size_t i = 0; i < 8; i++)
                    {
                        cout << "    - " << i << " " << options[i];
                    }

                    Essentials::Command<int>("\n- Opcao: ", rewardMenu);
                    continue;
                }

                if (rewardMenu > -1)
                {
                    cout << "\n- Opcao selecionada: " << options[rewardMenu] << "\n";

                    switch (rewardMenu)
                    {
                    case 0: // Add reward to backpack
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > -1 && selectedItem <= items.Size())
                        {
                            Item item = items.Get(selectedItem);
                            player.Backpack.Push(item);
                            items.Delete(selectedItem);
                            cout << "Item '" << item.Name << "' adicionado a mochila.\n";
                            selectedItem = -1;
                            rewardMenu = -1;
                            Essentials::Pause();
                        }
                        continue;
                    }

                    case 1: // Add reward to belt
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > -1 && selectedItem <= items.Size())
                        {

                            if (player.Belt.Size() < player.BeltSlots)
                            {
                                Item item = items.Get(selectedItem);
                                items.Delete(selectedItem);     
                                player.Belt.Push(item);
                                cout << "Item '" << item.Name << "' adicionado ao cinto.\n";
                            }
                            else
                            {
                                cout << "Seu cinto está cheio!\n";
                            }

                            selectedItem = -1;
                            rewardMenu = -1;
                            Essentials::Pause();
                        }
                        else
                        {
                            cout << "Item invalido.\n";
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        continue;
                    }

                    case 2: // Discard item from backpack
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item da mochila ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > 0 && selectedItem <= player.Backpack.Size())
                        {
                            Item item = player.Backpack.Pop();
                            cout << "- Você descartou o item '" << item.Name << "' da mochila.\n";
                            Essentials::Pause();
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        else
                        {
                            cout << "Item invalido.\n";
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        continue;
                    }

                    case 3: // Discard item from belt
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item do cinto ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > 0 && selectedItem <= player.Belt.Size())
                        {
                            Item item = player.Belt.Get(selectedItem);
                            player.Belt.Delete(selectedItem);
                            cout << "- Você descartou o item '" << item.Name << "' do cinto.\n";
                            Essentials::Pause();
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        else
                        {
                            cout << "Item invalido.\n";
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        continue;
                    }

                    case 4: // Send item to belt
                    {
                        cout << "Item enviado para o cinto.\n";
                        Essentials::Pause();
                        player.GetItemToBelt();
                        rewardIsOpen = false;
                        continue;
                    }

                    case 5: // View backpack item details
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item da mochila ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > -1 && selectedItem <= items.Size())
                        {
                            Item item = items.Get(selectedItem);
                            itemStatusScreen.RenderImageText(item);
                            Essentials::Pause();
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        else
                        {
                            cout << "Item invalido.\n";
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        continue;
                    }

                    case 6: // View belt item details
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item do cinto ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > 0 && selectedItem <= player.Belt.Size())
                        {
                            Item item = player.Belt.Get(selectedItem - 1);
                            itemStatusScreen.RenderImageText(item);
                            Essentials::Pause();
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        else
                        {
                            cout << "Item invalido.\n";
                            selectedItem = -1;
                            rewardMenu = -1;
                        }
                        continue;
                    }

                    case 7: // Continue
                    {
                        cout << "Continuando...\n";
                        rewardIsOpen = false;
                        break;
                    }

                    default:
                    {
                        cout << "Escolha invalida. Tente novamente.\n";
                        rewardMenu = -1;
                    }
                    }
                }
            }
        }
        break;

        case 4: // End Level
        {
            Essentials::Pause();
        }
        break;

        case 5: // Cenary
        {
            Essentials::Pause();
        }
        break;

        case 6: // Inventory
        {
            int inventoryMenu = -1;
            int selectedItem = -1;
            bool inventoryIsOpen = true;

            while (inventoryIsOpen)
            {
                Essentials::Clear();
                player.RenderImageText();
                playerStatusScreen.RenderImageText(player);

                string options[6] = {
                    "Enviar item para o cinto\n",
                    "Usar item\n",
                    "Descartar item da mochila\n",
                    "Descartar item do cinto\n",
                    "Ver item detalhadamente\n",
                    "Voltar para o jogo\n",
                };

                cout << "\n- Inventario:\n";
                cout << "\n   Backpack:\n";

                // If the inventory use list structure and show the list items
                // if(player.Backpack.Size() == 0) {
                //     cout << "    - Sem nenhum item\n";
                // }

                cout << "    - Quantidade de itens na mochila:" << player.Backpack.Size();
                cout << "\n";

                // If the inventory use list structure and show the list items
                // player.Backpack.ForEach([](Item item, int index) {
                //     cout << "    - " + to_string(index) + " " + item.Name + "\n";
                // });

                cout << "\n   Belt:\n";

                if (player.Belt.Size() == 0)
                {
                    cout << "    - Sem nenhum item\n";
                }

                player.Belt.ForEach([](Item item, int index)
                                    { cout << "    - " + to_string(index) + " " + item.Name + "\n"; });

                if (inventoryMenu == -1 && selectedItem == -1)
                {
                    cout << "\n   Comandos:\n";

                    for (size_t i = 0; i < 6; i++)
                    {
                        cout << "    - " << i << " " << options[i];
                    }

                    Essentials::Command<int>("\n- Opcao: ", inventoryMenu);
                    continue;
                }

                if (inventoryMenu > -1)
                {

                    cout << '\n'
                         << "- Opcao selecionada: " << options[inventoryMenu] << "\n";

                    switch (inventoryMenu)
                    {
                    case 0: // Send item to belt
                    {
                        cout << "Item enviado para o cinto.\n";
                        Essentials::Pause();
                        player.GetItemToBelt();
                        inventoryIsOpen = false;
                    }
                    break;

                    case 1: // Use item
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > 0 && selectedItem <= player.Belt.Size())
                        {
                            Item item = player.Belt.Get(selectedItem);

                            if (item.Consumable)
                            {
                                cout << "- Voce utilizou o item " << item.Name;
                                player.UseItem(item);
                                inventoryIsOpen = false;
                            }
                            else
                            {
                                cout << "- O item " << item.Name << " nao pode ser consumido";
                            }
                            cout << '\n';
                            inventoryMenu = -1;
                            selectedItem = -1;
                            Essentials::Pause();
                        }

                        continue;
                    }
                    break;

                    case 2: // Discart item from backpack
                    {
                        if (selectedItem > 0 && selectedItem <= player.Backpack.Size())
                        {
                            // If the inventory use list structure and show the list items
                            // Item item = player.Backpack.Get(player.Backpack.Size() - 1);
                            // player.Backpack.Delete(player.Backpack.Size() - 1);

                            Item item = player.Backpack.Pop();
                            cout << "- Voce removeu da mochila o item " << item.Name;
                            Essentials::Pause();
                            inventoryIsOpen = false;
                            continue;
                        }
                        else
                        {
                            cout << "Item invalido.\n";
                            selectedItem = -1;
                            inventoryMenu = -1;
                        }
                    }
                    break;

                    case 3: // Discart item from belt
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > 0 && selectedItem <= player.Belt.Size())
                        {
                            Item item = player.Belt.Get(selectedItem);
                            player.Belt.Delete(selectedItem);
                            cout << "- Voce removeu do cinto o item " << item.Name;
                            Essentials::Pause();
                            inventoryIsOpen = false;
                            continue;
                        }
                        else
                        {
                            cout << "Item invalido.\n";
                            selectedItem = -1;
                            inventoryMenu = -1;
                        }
                    }
                    break;

                    case 4: // Item details
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                            cout << '\n';
                        }
                        else if (selectedItem > 0 && selectedItem <= player.Belt.Size())
                        {
                            Item item = player.Belt.Get(selectedItem);
                            itemStatusScreen.RenderImageText(item);
                            Essentials::Pause();
                            inventoryIsOpen = false;
                        }
                        else
                        {
                            cout << "Item invalido.\n";
                            selectedItem = -1;
                            inventoryMenu = -1;
                        }
                    }
                    break;

                    case 5:
                    {
                        cout << "Saindo do inventario.\n";
                        inventoryIsOpen = false;
                        currentMenu = 1;
                    }
                    break;

                    default:
                    {
                        cout << "Opcao invalida. Tente novamente.\n";
                        inventoryMenu = -1;
                    }
                    break;
                    }
                }
            }
        }
        break;

        default:
        {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
        break;
        }
    }
    
    return 0;
}