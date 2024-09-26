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
#include "Services/Reward/Reward.cpp"

using namespace std;

int main()
{
    int level = 1;
    bool end = false;
    int currentMenu = 1;
    Rand rand;

    int numberReward = 0;
    int previousLevel = 0;
    StartingScreen startingScreen;
    PlayerStatusScreen playerStatusScreen;
    ItemStatusScreen itemStatusScreen;

    Player player("Assets/Text-Images/Player/player.txt");
    int numberRewardLevel = 0;

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
                case 0: 
                {
                    currentMenu = 6;
                    continue;
                }
                case 1:
                {
                    if(numberReward == 1){
                        currentMenu = 2;
                        continue;
                    }
                    int rewardRef = 2 + numberRewardLevel;

                    if(numberReward == 2 || (numberReward ==  rewardRef && numberRewardLevel > 0)){
                        numberRewardLevel = numberReward;

                        string optScreens[9] = {
                            "wood-house.txt",
                            "montain-house-type-1,txt",
                            "montain-house-type-2.txt",
                            "japonese-house.txt",
                            "default-house-type-1.txt",
                            "default-house-type-2.tzt",
                            "default-house-type-3.txt",
                            "default-house-type-4.txt",
                            "caslte.txt",
                        };

                        int randomIndex = std::rand() % 9;

                        Essentials::RenderImageText("Assets/Text-Images/Scenes/" + optScreens[randomIndex]);

                        level++;

                    }
                    bool isBattle = Rand::RandomChance(50);
                    if(isBattle){
                         currentMenu = 2;
                         continue;
                    }
                    currentMenu = 3;
                    numberReward++;
                    continue;
                }
            } 
            
            Essentials::Pause(); 
        }
        break;

        case 2: // Figthing
        {

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
                        currentMenu = 1;
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
            cout << "Opcao invalida. Tente novamente." << endl;
        }
        break;
        }
    }
    
    return 0;
}
