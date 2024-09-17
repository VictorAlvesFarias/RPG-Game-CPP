#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BaseEntity {
    public: string ImageTextPath;

    public: void RenderImageText() {
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

    public: void Pause(){
        cin.get();
    }
};
