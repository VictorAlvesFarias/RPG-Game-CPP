#include <iostream>
#include <locale>
#include <vector>
#include "utils/List/List.cpp"
#include "utils/String/String.cpp"
#include "Screens/BaseScreen/BaseScreen.cpp"
#include "Entities/BaseEntity/BaseEntity.cpp"
#include "Screens/StartingScreen.cpp"
#include "Screens/PlayerStatusScreen.cpp"
#include "Screens/ItemStatusScreen.cpp"
#include "Entities/Item/Item.cpp"
#include "Entities/Player/Player.cpp"
#include "Entities/Sqm/Sqm.cpp"
using namespace std;

void InitPlayer(Player& player) {
    player.Backpack.Push(Item("Sword",false));
    player.Backpack.Push(Item("Knife",false ));
    player.Backpack.Push(Item("Spear",false));
    player.Belt.Push(Item("Regen Health Potion Large",true));
    player.Belt.Push(Item("Regen Health Potion Small",true));
    player.Belt.Push(Item("Regen Health Potion Middle",true));
}

template <typename T>
void Command(string message, T &response) {
    cout << message;
    cin >> response;
}

void Clear(){
    system("cls");
}

void Pause(){
    cout<<'\n';
    cout<<'\n';
    system("PAUSE");
}

int main()
{    
    int level = 0; //Use this variable to scale difficulty algorithms
    bool end = false;
    int currentMenu = 1;

    StartingScreen startingScreen;
    PlayerStatusScreen playerStatusScreen;
    ItemStatusScreen itemStatusScreen;
    Player player("Assets/Text-Images/Player/player.txt");
    
    InitPlayer(player);

    while (!end)
    {
        switch (currentMenu)
        {
            case 1: //Starting
            {
                Clear();
                startingScreen.RenderImageText();
                Pause();
                currentMenu = 6;
            }
            break;

            case 2: //Fi    gthing
            {
                Pause();
            }
            break;

            case 3: //Reward
            {
                Pause();
            }
            break;

            case 4: //End Level
            {
                Pause();
            }
            break;

            case 5: //Cenary
            {
                Pause();
            }
            break;
            
            case 6: // Inventory
            {
                int inventoryMenu = -1;
                int selectedItem = -1;
                bool inventoryIsOpen = true;

                while (inventoryIsOpen)
                {
                    Clear();

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

                    cout << "    - Quantidade de itens na mochila:"<< player.Backpack.Size();
                    
                    // If the inventory use list structure and show the list items 
                    // player.Backpack.ForEach([](Item item, int index) {
                    //     cout << "    - " + to_string(index) + " " + item.Name + "\n";
                    // });

                    cout << "\n   Belt:\n";

                    if(player.Belt.Size() == 0) {
                        cout << "    - Sem nenhum item\n";
                    }

                    player.Belt.ForEach([](Item item, int index) {
                        cout << "    - " + to_string(index) + " " + item.Name + "\n";
                    });

                    if (inventoryMenu == -1 && selectedItem == -1) {
                        cout << "\n   Comandos:\n";

                        for (size_t i = 0; i < 6; i++)
                        {
                            cout<<"    - " << i << " " << options[i] ;
                        }
                        
                        Command<int>("\n- Opcao: ", inventoryMenu);
                        continue;
                    }
                    
                    if(inventoryMenu > -1) {
                        
                        cout <<'\n'<< "- Opcao selecionada: " << options[inventoryMenu] << "\n";
                        switch (inventoryMenu)
                        {
                            case 0:
                            {
                                cout << "Item enviado para o cinto.\n";
                                Pause();
                                player.GetItemToBelt();
                                inventoryIsOpen = false;
                            }
                            break;

                            case 1:
                            {
                                if(selectedItem == -1) {
                                    Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                                    cout << '\n';
                                }
                                else {
                                    Item item = player.Belt.Get(selectedItem);
                                    
                                    if(item.Consumable){
                                        cout << "- Voce utilizou o item " << item.Name;
                                        player.UseItem(item);
                                        inventoryIsOpen = false;
                                    }
                                    else {
                                        cout << "- O item " << item.Name << " nao pode ser consumido";
                                    }
                                    cout<<'\n';
                                    inventoryMenu =-1;
                                    selectedItem = -1;
                                    Pause();
                                }

                                continue;
                            }
                            break;

                            case 2:
                            {                     
                                
                                // If the inventory use list structure and show the list items 
                                // Item item = player.Backpack.Get(player.Backpack.Size() - 1);
                                // player.Backpack.Delete(player.Backpack.Size() - 1);
                                
                                Item item = player.Backpack.Pop();
                                cout << "- Voce removeu da mochila o item " << item.Name;
                                Pause();
                                inventoryIsOpen = false;
                                continue;
                            }
                            break;

                            case 3:
                            {
                                if(selectedItem == -1) {
                                    Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                                    cout << '\n';
                                }
                                else {
                                    Item item = player.Belt.Get(selectedItem);
                                    player.Belt.Delete(selectedItem);
                                    cout << "- Voce removeu do cinto o item " << item.Name;
                                    Pause();
                                    inventoryIsOpen = false;
                                    continue;
                                }
                            }
                            break;

                            case 4:
                            {
                                if(selectedItem == -1) {
                                    Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                                    cout << '\n';
                                }
                                else {
                                    Item item = player.Belt.Get(selectedItem);
                                    itemStatusScreen.RenderImageText(item);
                                    Pause();
                                    inventoryIsOpen = false;
                                }
                            }
                            break;

                            case 5:
                            {
                                cout << "Saindo do inventário.\n";
                                inventoryIsOpen = false;
                            }
                            break;

                            default:
                            {
                                cout << "Opção inválida. Tente novamente.\n";
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
                cout << "Opção inválida. Tente novamente." << endl;
            }
            break;
        }
    }

    return 0;
}
