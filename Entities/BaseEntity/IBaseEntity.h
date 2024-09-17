#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BaseEntity {
    public:
        string ImageTextPath;

        void RenderImageText();
        void Pause();
};