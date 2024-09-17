#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BaseScreen {
    public: void Pause(){
        cin.get();
    }
    public: void Clear(){
        system("cls");
    }
};
