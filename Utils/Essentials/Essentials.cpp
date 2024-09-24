#include "IEssentials.h"
#include <locale>
#include <iostream>
#include <string>
#include <fstream>
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


void Essentials::RenderImageText(string path) {
    ifstream file(path);
    string linha;

    if (!file.is_open()) {
        throw "Error to open file";
    }

    while (getline(file, linha)) {
        cout << linha << endl;
    }

    file.close();
}

