#include <iostream>
#include "IBaseEntity.h"

void BaseEntity::RenderImageText() {
    ifstream file(ImageTextPath);
    string linha;

    if (!file.is_open()) {
        throw "Error to open file";
    }

    while (getline(file, linha)) {
        cout << linha << endl;
    }

    file.close();
}

void BaseEntity::Pause() {
    cin.get();
}
