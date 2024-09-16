#include <iostream>
#include <locale>
#include "utils/List/List.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "");  
    bool end = false;
    int currentMenu = 0;
    List<int> teste;

    while (!end) {
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Starting game" << endl;
        cout << "2 - Menu" << endl;
        cout << "3 - Game" << endl;
        cout << "4 - Player status" << endl;
        cout << "5 - Inventory" << endl;
        cout << "6 - Fechar aplicação" << endl;
        cout << "Escolha: ";
        cin >> currentMenu;

        switch (currentMenu) {
        case 1:
            cout << "Starting game" << endl;
            break;
        case 2:
            cout << "Menu" << endl;
            break;
        case 3:
            cout << "Game" << endl;
            break;
        case 4:
            cout << "Player status" << endl;
            break;
        case 5:
            cout << "Inventory" << endl;
            break;
        case 6:
            cout << "Fechando aplicação..." << endl;
            end = true;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}
