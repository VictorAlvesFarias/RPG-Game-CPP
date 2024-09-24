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
    int currentMenu = 3;

    StartingScreen startingScreen;
    PlayerStatusScreen playerStatusScreen;
    ItemStatusScreen itemStatusScreen;
    Player player("Assets/Text-Images/Player/player.txt");
  
    while (!end)
    {
        switch (currentMenu)
        {
            case 1: //Starting
            {
                Essentials::Clear();
                startingScreen.RenderImageText();
                Essentials::Pause();
                currentMenu = 3;
            }
            break;

            case 2: //Fi    gthing
            {
                Essentials::Pause();
            }
            break;

            case 3: //Reward
            {
                Reward reward;

                List<Item> items = reward.RewardItem(5);

                if(items.Size() == 0){
                    cout << "Ops, Você não encontrou nenhum item.\n";
 
                    break;
                }

                cout << "\nItens ganhados:\n";
 
                items.ForEach([](Item item, int index) {
                        cout << "    - " + to_string(index + 1) + " " + item.Name + "\n";
                    });

                int choice;
                cout << "\nComandos:\n";
                cout << "1. Colocar na mochila\n";
                cout << "2. Colocar no cinto\n";
                cout << "3. Continuar\n";
                cout << "Escolha: ";

                cin >> choice; 

                if(choice == 1){
                    int itemIndex;
                    cout << "Escolha o item (1-" << items.Size() << "): ";
                    cin >> itemIndex;

                    if (itemIndex < 1 || itemIndex > items.Size()) {
                        cout << "Item invalido. Tente novamente.\n";
                        continue;
                    }

                    player.Backpack.Push(items.Get(itemIndex - 1));
                    cout << "Item '" << items.Get(itemIndex - 1).Name << "' adicionado a mochila.\n";
                }
                else if(choice == 2){
                    int itemIndex;
                    cout << "Escolha o item (1-" << items.Size() << "): ";
                    cin >> itemIndex;

                    if (itemIndex < 1 || itemIndex > items.Size()) {
                        cout << "Item invalido. Tente novamente.\n";
                        continue;
                    }

                    player.Belt.Push(items.Get(itemIndex - 1));
                    cout << "Item '" << items.Get(itemIndex - 1).Name << "' adicionado ao cinto.\n";
                }
                else if(choice == 3){
                    cout << "Continuando...\n";
                }
                else {
                    cout << "Escolha inválida. Tente novamente.\n";
                }
                 
                break; 
            }
            break;

            case 4: //End Level
            {
                Essentials::Pause();
            }
            break;

            case 5: //Cenary
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
                        
                        Essentials::Command<int>("\n- Opcao: ", inventoryMenu);
                        continue;
                    }
                    
                    if(inventoryMenu > -1) {
                        
                        cout <<'\n'<< "- Opcao selecionada: " << options[inventoryMenu] << "\n";
                        switch (inventoryMenu)
                        {
                            case 0:
                            {
                                cout << "Item enviado para o cinto.\n";
                                Essentials::Pause();
                                player.GetItemToBelt();
                                inventoryIsOpen = false;
                            }
                            break;

                            case 1:
                            {
                                if(selectedItem == -1) {
                                    Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
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
                                    Essentials::Pause();
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
                                Essentials::Pause();
                                inventoryIsOpen = false;
                                continue;
                            }
                            break;

                            case 3:
                            {
                                if(selectedItem == -1) {
                                    Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                                    cout << '\n';
                                }
                                else {
                                    Item item = player.Belt.Get(selectedItem);
                                    player.Belt.Delete(selectedItem);
                                    cout << "- Voce removeu do cinto o item " << item.Name;
                                    Essentials::Pause();
                                    inventoryIsOpen = false;
                                    continue;
                                }
                            }
                            break;

                            case 4:
                            {
                                if(selectedItem == -1) {
                                    Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                                    cout << '\n';
                                }
                                else {
                                    Item item = player.Belt.Get(selectedItem);
                                    itemStatusScreen.RenderImageText(item);
                                    Essentials::Pause();
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