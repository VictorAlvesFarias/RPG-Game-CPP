#include <locale>
#include <iostream>
#include <string>

using namespace std;

class Essentials {
    
    public:template <typename T> static void Command(string message, T &response);
    public: static void Clear();
    public: static void Pause();
};