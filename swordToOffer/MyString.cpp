#include<iostream>
#include<cstring>

using namespace std;

class MyString
{
public:
    MyString(char* pData = nullptr);
    MyString(const MyString& str);

    MyString& operator=(const MyString& str);
    ~MyString();

    void Print();

private:
    char* m_pData;
};

MyString::MyString(char* pData)
{
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

MyString::MyString(const MyString& str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

MyString& MyString::operator=(const MyString& str)
{
    if(&str == this)
        return *this;

    delete[] m_pData;
    m_pData = nullptr;

    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];

    strcpy(m_pData, str.m_pData);

    return *this;
}

MyString::~MyString()
{
    delete[] m_pData;
}

// ====================测试代码====================
void MyString::Print()
{
    printf("%s", m_pData);
}

void Test1()
{
    printf("Test1 begins:\n");

    char* text = "Hello world";

    MyString str1(text);
    MyString str2;
    str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

// 赋值给自己
void Test2()
{
    printf("Test2 begins:\n");

    char* text = "Hello world";

    MyString str1(text);
    str1 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

// 连续赋值
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    MyString str1(text);
    MyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

