#include "BaseScreen/IBaseScreen.h"
using namespace std;

class StartingScreen : public BaseScreen
{
    public:void RenderImageText()
    {
        cout << "\n"; 
        cout << "\n"; 
        cout << "\n"; 
        cout << "\n"; 
        cout << "\n"; 
        cout << "   ___     __              __                 ____               __ \n";
        cout << "  / _ |___/ /  _____ ___  / /___ _________   / __ \\__ _____ ___ / /_\n";
        cout << " / __ / _  / |/ / -_) _ \\/ __/ // / __/ -_) / /_/ / // / -_|_-</ __/\n";
        cout << "/_/ |_\\_,_/|___/\\__/_//_/\\__/\\_,_/_/  \\__/  \\___\\_\\_,_/\\__/___/\\__/\n";
        cout << "                        Press enter to play                         \n";
        cout << "\n"; 
        cout << "\n"; 
        cout << "\n"; 
        cout << "\n"; 
        cout << "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo"; 
    };
 
};

