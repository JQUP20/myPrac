#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <cstring>
#include <fstream>

class SpeechManager
{
public:

    SpeechManager();

    ~SpeechManager() {}

    void show_Menu();

    void exitSystem();

    void initSpeech();

    void createSpeaker();

    void startSpeech();

    void speechDraw();

    void speechContest();

    void showScore();

    void saveRecord();

    void loadRecord();

    void showRecord();

    void clearRecord();

private:

    //判断文件是否为空
    bool fileIsEmpty;
    
    //存放往届记录的容器
    map<int ,vector<string>> m_Record;

    //保存第一轮比赛选手编号容器
    vector<int> v1;

    //第一轮晋级选手编号容器
    vector<int> v2;

    //胜出前三名选手编号容器
    vector<int> vVictory;

    //存放编号以及对应具体选手容器
    map<int, Speaker> m_Speaker;

    //存放比赛轮数
    int m_Index;
};

