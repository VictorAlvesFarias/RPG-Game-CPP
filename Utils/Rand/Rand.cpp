#pragma once
#include "IRand.h"
#include <functional> 
using namespace std;

Rand:: Rand(){

}

int Rand::Randomize(int min, int max) {
    srand(static_cast<unsigned int>(time(0)));
    return min + rand() % (max - min + 1);
}

bool Rand::RandomChance(int percentage) {
    srand(static_cast<unsigned int>(time(0)));
    return rand() % 100 < percentage;
}