#include <iostream>
#include <locale>
#include "Utils/List/List.cpp"
#include "Utils/Essentials/Essentials.cpp"
#include "Config/Config.cpp"
#include "Utils/Rand/Rand.cpp"
#include "Utils/Stack/Stack.cpp"
#include "Utils/String/String.cpp"
#include "Screens/BaseScreen/BaseScreen.cpp"
#include "Entities/BaseEntity/BaseEntity.cpp"
#include "Screens/StartingScreen.cpp"
#include "Screens/PlayerStatusScreen.cpp"
#include "Screens/ItemStatusScreen.cpp"
#include "Entities/Item/Item.cpp"
#include "Entities/Player/Player.cpp"
#include "Entities/Sqm/Sqm.cpp"

using namespace std;

List<Item> RewardItem(int level)
{
    List<Item> rewardItems;
    int itemsQuantity = Rand::Randomize(1, 5);

    for (int i = 0; i < itemsQuantity; i++)
    {
        int indexItem = Rand::Randomize(0, 49);
        Item item = Config::items[indexItem];

        rewardItems.Push(Config::items[indexItem]);
    }

    return rewardItems;
}

void InitPlayer(Player &player, int level)
{
    List<Item> items = RewardItem(level);

    items.ForEach([&player](Item item, int index)
                  { player.Backpack.Push(item); });
}

int main()
{
    int level = 0; // Use this variable to scale difficulty algorithms
    bool end = false;
    int currentMenu = 1;
    Rand rand;

    StartingScreen startingScreen;
    PlayerStatusScreen playerStatusScreen;
    ItemStatusScreen itemStatusScreen;

    Player player("Assets/Text-Images/Player/player.txt");

    InitPlayer(player, level);

    while (!end)
    {
        switch (currentMenu)
        {
        case 1: // Starting
        {
            Essentials::Clear();
            startingScreen.RenderImageText();
            Essentials::Pause();
            currentMenu = 2;
        }
        break;

        case 2: // Figthing
        {

            PlayerStatusScreen playerStatusScreen;
            player.SetLevel(level, player);
            int health = rand.Randomize(20, 40);
            int damage = rand.Randomize(10, 20);
            bool endFight = false;
            int numberActions = 0;
            string options[3] = {
                    "Atacar!\n",
                    "Defender!\n",
                    "Sair do jogo\n",
            };


            int action = -1;

            Player enemy(health, damage);
            enemy.SetLevel(level, enemy);
            enemy.GenerateBonus(enemy);

            cout << "Um inimigo apareceu, o que deseja fazer?" << endl;


            while (!endFight)
            {
                playerStatusScreen.RenderImageText(player);
                playerStatusScreen.RenderImageTextEnemy(enemy);

                cout << "Qual a sua proxima acao?" << endl;
                for (size_t i = 0; i < 3; i++)
                {
                    cout << "    - " << i << " " << options[i];
                }
                cin >> action;
                switch (action)
                {
                case 0:
                {
                    //  player.Atack(enemy);

                    if (numberActions == 2)
                    {

                        //  numberActions++;
                        if (enemy.EnemyHealth < 0)
                        {
                            cout << "O inimigo foi derrotado!" << endl;

                            endFight = true;
                            currentMenu = 3;

                            continue;
                        }

                        int chance = (enemy.GetMaxHealthEnemy() - enemy.GetHealthEnemy());


                        if (rand.RandomChance(chance*2))
                        {

                            enemy.HealLifeEnemy((enemy.GetMaxHealthEnemy() - enemy.GetHealthEnemy())/3);
                            cout << (enemy.GetMaxHealthEnemy() - enemy.GetHealthEnemy())/3;
                        } 
                        else
                        {

                            enemy.AtackAsEnemy(player);

                            if (player.Health < 0) 
                            {
                                cout << "O heroi foi derrotado" << endl;
                                endFight = true;
                            }

                            if (rand.RandomChance(50)) 
                            {

                                enemy.AtackAsEnemy(player);

                                if (player.Health < 0) {
                                    cout << "O heroi foi derrotado";
                                    endFight = true;
                                }
                            }
                        }

                        numberActions = 0;

                    }
                    else
                    {
                        player.Atack(enemy);
                        numberActions++;

                        if (enemy.EnemyHealth < 0)
                        {
                            cout << "O inimigo foi derrotado!";
                            endFight = true;
                            currentMenu = 3;
                            continue;
                        }
                    }

                    action = -1;
                    //continue;

                    break;
                }

                case 1:
                {
                    if (rand.RandomChance(40))
                    {
                        player.Defend();
                        action = -1;
                        continue;
                    }
                    cout << "O heroi não conseguiu denfender!";
                    enemy.AtackAsEnemy(player);
                    if (player.Health < 0)
                    {
                        cout << "O heroi foi derrotado";
                        endFight = true;
                    }
                    action = -1;
                    continue;
                }
                break;
                // case inventory
                case 3:
                {

                }
                break;
                }
            }
        }
        break;

        case 3: // Reward
        {
            Essentials::Pause();
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
                    case 0: // Send to belt
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
                            if (selectedItem == -1)
                            {
                                inventoryMenu = -1;
                            }
                            cout << '\n';
                        }
                        else
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

                    case 2: // Discard item to backpack
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

                    case 3: // Discard item to belt
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                            if (selectedItem == -1)
                            {
                                inventoryMenu = -1;
                            }
                            cout << '\n';
                        }
                        else
                        {
                            Item item = player.Belt.Get(selectedItem);
                            player.Belt.Delete(selectedItem);
                            cout << "- Voce removeu do cinto o item " << item.Name;
                            Essentials::Pause();
                            inventoryIsOpen = false;
                            continue;
                        }
                    }
                    break;

                    case 4: // Item details
                    {
                        if (selectedItem == -1)
                        {
                            Essentials::Command<int>("  Selecione o item ( -1 para cancelar ): ", selectedItem);
                            if (selectedItem == -1)
                            {
                                inventoryMenu = -1;
                            }
                            cout << '\n';
                        }
                        else
                        {
                            Item item = player.Belt.Get(selectedItem);
                            itemStatusScreen.RenderImageText(item);
                            Essentials::Pause();
                            inventoryIsOpen = false;
                        }
                    }
                    break;

                    case 5: // Return
                    {
                        cout << "Saindo do inventário.\n";
                        inventoryIsOpen = false;
                        currentMenu = 1;
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
