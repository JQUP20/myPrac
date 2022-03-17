#include "speechManager.h"

SpeechManager::SpeechManager()
{
    this->initSpeech();
    this->createSpeaker();

    this->loadRecord();
}

void SpeechManager::show_Menu()
{
    cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

void SpeechManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();

    this->m_Index = 1;

    this->m_Record.clear();
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for(int i = 0; i < nameSeed.size(); i++)
    {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;

        for(int j = 0; j < 2; j++)
            sp.m_Score[j] = 0;

        this->v1.push_back(i + 10001);

        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechManager::startSpeech()
{
    	//第一轮开始比赛

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechContest();

	//3、显示晋级结果
	this->showScore();

	//第二轮开始比赛
	this->m_Index++;
	//1、抽签
	this->speechDraw();
	//2、比赛
	speechContest();
	//3、显示最终结果
	this->showScore();
	//4、保存分数到文件中
	this->saveRecord();

	//重置比赛 ，获取记录
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();



	cout << "本届比赛完毕！" << endl;
}

void SpeechManager::speechDraw()
{
    cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
	cout << "--------------------------" << endl;
	cout << "抽签后演讲顺序如下： " << endl;

    if(this->m_Index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for(auto i : v1)
            cout << i << " ";
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for(auto i : v1)
            cout << i << " ";
        cout << endl;
    }

    cout << "-----------------" << endl;

    cout << endl;
}

void SpeechManager::speechContest()
{
    cout << "----------- 第" << this->m_Index << " 轮比赛正式开始 --------------" << endl;

    //准备临时容器 存放小组成绩
    multimap<double, int, greater<double>> groupScore;

    int num = 0;        //记录人员个数  6人一组
    
    vector<int> v_Src;  //比赛选手容器
    if(this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }

    //遍历所有选手进行比赛
    for(auto it : v_Src)
    {
        num++;
        //评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;   // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

        sort(d.begin(), d.end(), greater<double>());
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double)d.size();
        
        this->m_Speaker[it].m_Score[this->m_Index - 1] = avg;

        groupScore.insert(make_pair(avg, it));     //key是得分，value是选手编号

        if(num % 6 == 0)
        {
            cout << "第" << num / 6 << "小组比赛名次： " << endl;
            for(auto gS : groupScore)
                cout << "编号： " << gS.second << " 姓名： " << this->m_Speaker[gS.second].m_Name << " 成绩： " << this->m_Speaker[gS.second].m_Score[this->m_Index - 1] << endl;

            int count = 0;
                   /* 
            for(auto& it : groupScore)
            {
                while(count < 3)
                {
                    if(this->m_Index == 1)
                        v2.push_back((it++).second);
                    else
                        vVictory.push_back((it++).second);
                    count++;
                }
            }
                */

            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
            groupScore.clear();

            cout << endl;
        }
    }
    cout << "------------------ 第" << this->m_Index << "轮比赛完毕 --------------" << endl;
}

void SpeechManager::showScore()
{
    cout << "------------------ 第" << this->m_Index << "轮晋级选手信息如下： -------------------" <<  endl;

	vector<int>v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号： " << *it << " 姓名： " << this->m_Speaker[*it].m_Name << " 得分： " <<
			this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	this->show_Menu();
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);
    for(auto it : vVictory)
        ofs << it << "," << this->m_Speaker[it].m_Score[1] << ",";

    ofs << endl;

    ofs.close();
    cout << "记录已经保持" << endl;

    this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in);

    if(!ifs.is_open())
    {
        this->fileIsEmpty = true;

        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    this->fileIsEmpty = false;

    ifs.putback(ch);

    string data;
    int index = 0;

    while(ifs >> data)
    {
        vector<string> v;

        int pos = -1;
        int start = 0;

        while(true)
        {
            pos = data.find(",", start);
            if(pos == -1)
            {
                break;
            }
            string temp = data.substr(start, pos - start);

            v.push_back(temp);
            start = pos + 1;
        }

        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
}

void SpeechManager::showRecord()
{
    if (this->fileIsEmpty)
	{
		cout << "文件为空或者文件不存在！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届 "
				<< "冠军编号：" << this->m_Record[i][0] << " 得分： " << this->m_Record[i][1] << " "
				<< "亚军编号：" << this->m_Record[i][2] << " 得分： " << this->m_Record[i][3] << " "
				<< "季军编号：" << this->m_Record[i][4] << " 得分： " << this->m_Record[i][5] << endl;
		}
	}
}

void SpeechManager::clearRecord()
{
    cout << "是否确定清空文件？" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		//初始化容器和属性
		this->initSpeech();

		//创建12名选手
		this->createSpeaker();

		//加载往届记录
		this->loadRecord();

		cout << "清空成功！" << endl;
	}
}







































































