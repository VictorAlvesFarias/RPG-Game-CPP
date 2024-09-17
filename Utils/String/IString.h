#pragma once
#include <string>
using namespace std;

class String {
    private: string value;
    
    public: String();
    
    public:string PadStart(string str, int length, char padChar = ' ');
    
    public:string PadStart(int str, int length, char padChar = ' ');
};
