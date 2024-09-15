#include <iostream>
using namespace std;

int main() {
    bool end = false;
    int currentMenu = 0;

    while (!end) {
        switch (currentMenu) {
        case 1:
            cout << "Starting game" << endl;

            break;
        case 2:
            end = true;
            cout << "Menu" << endl;

            break;
        case 3:
            end = true;
            cout << "Game" << endl;

            break;
        case 4:
            end = true;
            cout << "Player status" << endl;

            break;
        case 5:
            end = true;
            cout << "Inventory" << endl;

            break;
        default:
            break;
        }
    }

    return 0;
}
