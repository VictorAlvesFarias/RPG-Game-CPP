#include "IEssentials.h"
#include <locale>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
void Essentials::Command(string message, T &response) {
    cout << message;
    cin >> response;
}

void Essentials::Clear(){
    system("cls");
}

void Essentials::Pause(){
    cout<<'\n';
    cout<<'\n';
    system("PAUSE");
}