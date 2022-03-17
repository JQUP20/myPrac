#include <iostream>
using namespace std;
#include "speechManager.h"
#include <string>
#include <ctime>
int main()
{
    srand((unsigned int)time(nullptr));

    SpeechManager sm;

    int choice = 0;

    while(true)
    {
        sm.show_Menu();

        cout << "请输入您的选择： " << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                sm.startSpeech();
                break;
            case 2:
                sm.showRecord();
                break;
            case 3:
                sm.clearRecord();
                break;
            case 0:
                sm.exitSystem();
                break;
            default:
                break;
        }
    }

    return 0;
}
