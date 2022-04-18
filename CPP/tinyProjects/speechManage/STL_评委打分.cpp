#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <ctime>
using namespace std;

class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score= score;
    }

    string m_Name;
    int m_Score;
};

void createPerson(vector<Person>& v)
{
    string nameSeed = "ABCDE";
    for(int  i = 0; i < 5; i++)
    {
        string name = "Player";
        name += nameSeed[i];

        int score = 0;

        Person p(name, score);

        v.push_back(p);
    }
}

void setScore(vector<Person> &v)
{
    for(auto& p : v)
    {
        deque<int> d;
        for(int i = 0; i < 10; i++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }

        sort(d.begin(), d.end());

        d.pop_back();
        d.pop_front();

        int sum = 0;
        for(auto s : d)
        {
            sum += s;
       //     cout << sum << endl;
        }
        int avg = sum / d.size();
        cout << avg << endl;

        p.m_Score = avg;
    }
}

void setScore1(vector<Person> &v)
{

}

void showScore(vector<Person>& v)
{
    for(auto i : v)
        cout << "name: " << i.m_Name << "Average Score: " << i.m_Score << endl;
}

int main()
{
    srand((unsigned int)time(nullptr));

    vector<Person> v;
    createPerson(v);

    setScore(v);
   // showScore(v);

    for(auto i : v)
        cout << "name: " << i.m_Name << "Average Score: " << i.m_Score << endl;

    return 0;
}
