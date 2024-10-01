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
#include "Screens/EndingScreen.cpp"
#include "Screens/SqmScreen.cpp"
#include "Screens/PlayerStatusScreen.cpp"
#include "Screens/EnemyStatusScreen.cpp"
#include "Screens/ItemStatusScreen.cpp"
#include "Entities/Item/Item.cpp"
#include "Entities/Player/Player.cpp"
#include "Entities/Sqm/Sqm.cpp"
#include "Services/Reward/RewardService.cpp"
#include <iostream>

int main()
{
    int level = 1;
    bool end = false;
    int currentMenu = 1;
    int numberReward = 0;
    int previousLevel = 0;
    int rewardContext = 0;

    RewardService reward;
    StartingScreen startingScreen;
    EndingScreen endingScreen;
    PlayerStatusScreen playerStatusScreen;
    EnemyStatusScreen enemyStatusScreen;
    ItemStatusScreen itemStatusScreen;
    SqmScreen sqmScreen;
    Player player("Assets/Text-Images/Player/player.txt", reward.RewardItem(level));
    string enemiesScreeens[7] = {
        "Assets/Text-Images/Enemies/enemy-type-1.txt",
        "Assets/Text-Images/Enemies/enemy-type-2.txt",
        "Assets/Text-Images/Enemies/enemy-type-3.txt",
        "Assets/Text-Images/Enemies/enemy-type-4.txt",
        "Assets/Text-Images/Enemies/enemy-type-5.txt",
        "Assets/Text-Images/Enemies/enemy-type-6.txt",
        "Assets/Text-Images/Enemies/enemy-type-7.txt",
    };
    string screens[9] = {
        "Assets/Text-Images/Scenes/wood-house.txt",
        "Assets/Text-Images/Scenes/montain-house-type-1,txt",
        "Assets/Text-Images/Scenes/montain-house-type-2.txt",
        "Assets/Text-Images/Scenes/japonese-house.txt",
        "Assets/Text-Images/Scenes/default-house-type-1.txt",
        "Assets/Text-Images/Scenes/default-house-type-2.tzt",
        "Assets/Text-Images/Scenes/default-house-type-3.txt",
        "Assets/Text-Images/Scenes/default-house-type-4.txt",
        "Assets/Text-Images/Scenes/caslte.txt",
    };
    string sqmImage = screens[Rand::Randomize(0, 9)];

    while (!end)
    {
        switch (currentMenu)
        {

        case 1: // Starting
        {
            Essentials::Clear();
            startingScreen.RenderImageText();
            Essentials::Pause();
            currentMenu = 7;
        }
        break;

        case 2: // Figthing
        {
            int health = Rand::Randomize(20, 40);
            int damage = Rand::Randomize(10, 20);
            bool endFight = false;
            int numberActions = 0;
            int enemyActions = 0;
            int action = -1;

            Player enemy(enemiesScreeens[Rand::Randomize(0, 7)], reward.RewardItem(level));
            string options[2] = {
                "Atacar\n",
                "Tentar defender o proximo ataque \n",
            };

            enemy.SetLevel(level);
            enemy.GenerateBonus();
            cout << "- Voce encontrou um inmigo, mate ele!" << endl;

            while (!endFight)
            {
                Essentials::Clear();
                if (player.Health <= 0)
                {
                    cout << "\n- O heroi foi derrotado";
                    endingScreen.RenderImageText();
                    endFight = true;
                    Essentials::Pause();
                    abort();
                }

                if (enemy.Health < 0)
                {
                    cout << "\n- O inimigo foi derrotado!";
                    endFight = true;
                    currentMenu = 3;
                    continue;
                }

                enemy.RenderImageText();
                playerStatusScreen.RenderImageText(player);
                enemyStatusScreen.RenderImageText(enemy);

                if (numberActions == Config::PlayerActions && action == -1)
                {
                    cout << "\n- Turno do inimigo:\n";
                    Essentials::Pause();
                    action = 2;
                    continue;
                }

                if (action == -1 && numberActions < Config::PlayerActions)
                {
                    cout << "\n- Seu Turno:\n";
                    cout << "\n   Comandos:\n";

                    for (size_t i = 0; i < 2; i++)
                    {
                        cout << "    - " << i << " " << options[i];
                    }

                    Essentials::Command<int>("\n- Opcao: ", action);

                    continue;
                }

                switch (action)
                {
                case 0:
                {
                    cout << "\n- Seu Turno:\n";
                    int playerDamageAtack = player.Atack(enemy);
                    cout << "\n- Você atacou o inimigo e causou: " << playerDamageAtack << " de dano" << endl;
                    numberActions++;

                    Essentials::Pause();

                    action = -1;

                    continue;
                }
                break;
                case 2:
                {
                    if (Rand::RandomChance(40) && numberActions < Config::PlayerActions) // player defense
                    {
                        cout << "\n- Seu Turno:\n";
                        cout << "\n- O heroi conseguiu defender o ataque!" << endl;
                        enemyActions++;
                        action = -1;
                    }
                    else
                    {
                        cout << "\n- Turno do inimigo:\n";

                        if (enemyActions == 0)
                        {
                            int chance = (enemy.GetMaxHealth() - enemy.Health); // First atack
                            int enemyDamageAtack = enemy.Atack(player);

                            cout << "\n- O inimigo te atacou e causou: " << enemyDamageAtack << " de dano" << endl;

                            Essentials::Pause();

                            enemyActions++;

                            continue;
                        }
                        if (enemyActions == 1)
                        {
                            if (Rand::RandomChance(50)) // Second atack test
                            {
                                int enemyDamageAtack = enemy.Atack(player);
                                cout << "\n- O inimigo te atacou novamente e causou: " << enemyDamageAtack << " de dano" << endl;

                                Essentials::Pause();

                                enemyActions++;
                            }
                        }
                        else if (Rand::RandomChance(enemy.GetMaxHealth() - enemy.Health) && numberActions < Config::PlayerActions) // Enemy heal
                        {
                            int healValue = Rand::Randomize(0, (enemy.GetMaxHealth() - enemy.Health) / 3);

                            if (healValue > 0)
                            {
                                cout << "\n- O inimigo se curou em: " << healValue << " pontos de vida" << endl;
                            }
                            enemy.HealLife(healValue);

                            Essentials::Pause();

                            enemyActions++;
                        }

                        enemyActions = 0;
                    }

                    numberActions = 0;
                    action = -1;

                    continue;
                }
                break;
                }

                currentMenu = 3;
                numberReward++;

                break;
            }
        }
        break;

        case 3: // Reward
        {
            int rewardMenu = -1;
            int selectedItem = -1;
            bool rewardIsOpen = true;

            List<Item> items = reward.RewardItem(level);
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
                Essentials::RenderImageText("Assets/Text-Images/Misc/coin.txt");

                if (items.Size() == 0)
                {
                    cout << "- Ops, parece que esse local esta vazio, voce nao encontrou nenhum item.\n";
                    Essentials::Pause();
                    rewardIsOpen = false;
                    break;
                }
                cout << "\n- Itens ganhos:\n";
                items.ForEach([](Item item, int index)
                              { cout << "    - " + to_string(index) + " " + item.Name + "\n"; });

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
                        else if (selectedItem > -1 && player.GetBeltSlotsQuantity() <= items.Size())
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
                        currentMenu = 7;
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

                    case 2: // Discard item from backpack
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

                    case 3: // Discard item from belt
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
                        currentMenu = 7;
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

        case 7: // Scene
        {

            bool mainMenuIsOpen = true;
            int mainMenu;

            string options[2] = {
                "Ver inventário\n",
                "Continuar\n",
            };

            Essentials::Clear();
            Essentials::RenderImageText(sqmImage);
            sqmScreen.RenderImageText(level);
            cout << "\n \n- Continue sua jornada heroi:\n";
            cout << "\n   Comandos:\n";

            for (size_t i = 0; i < 2; i++)
            {
                cout << "   - " << i << " " << options[i];
            }

            Essentials::Command<int>("\n- Opcao: ", mainMenu);
            mainMenuIsOpen = false;

            switch (mainMenu)
            {
            case 0:
            {
                currentMenu = 6;
                continue;
            }

            case 1:
            {
                bool isBattle = Rand::RandomChance(Config::BattleChace);
                int rewardRef = 2 + rewardContext;

                if (numberReward == 1)
                {
                    currentMenu = 2;
                    continue;
                }

                if (numberReward == 2 || (numberReward == rewardRef && rewardContext > 0))
                {
                    rewardContext = numberReward;
                    sqmImage = screens[Rand::Randomize(0, 9)];
                    level++;
                }

                if (isBattle)
                {
                    currentMenu = 2;
                    continue;
                }

                currentMenu = 3;
                numberReward++;

                continue;
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
