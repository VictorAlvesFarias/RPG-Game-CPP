#pragma once
#include "IRand.h"
#include <functional> 
using namespace std;

Rand:: Rand(){
    srand(time(0));
}

int Rand::Randomize(int min, int max) {
    return min + rand() % (max - min + 1);
}

bool Rand::RandomChance(int percentage) {
    return rand() % 100 < percentage;
}