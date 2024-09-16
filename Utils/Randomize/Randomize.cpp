#include <iostream>

using namespace std;

int Randomize(int min, int max) {

    return min + rand() % (max - min + 1);
}

bool RandomChance(int percentage) {
    return rand() % 100 < percentage;
}