#include <iostream>
#include <cstring>
using namespace std;

class CString
{
public:
    CString(char* pData = nullptr);
    CString(const CString& str);
    ~CString(void);

    CString& operator = (const CString& str);

    void Print();

private:
    char *m_pData;
};

CString::CString(char *pData)
{
    cout << "有参构造。。。" << endl;
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int len = strlen(pData);
        m_pData = new char[len + 1];
        strcpy(m_pData, pData);
    }
}

CString::CString(const CString& str)
{
    cout << "拷贝构造" << endl;
    if(str.m_pData != nullptr)
    {
        int len = strlen(str.m_pData);
        m_pData = new char[len + 1];
        strcpy(m_pData, str.m_pData);
    }
}

CString::~CString()
{
    cout << "~析构函数" << endl;
    delete[] m_pData;
}

CString& CString::operator = (const CString& str)
{
    cout << "赋值函数" << endl;
    if(&str == this)
        return *this;

    delete[] m_pData;
    m_pData = nullptr;

    int len = strlen(str.m_pData);
    m_pData = new char[len + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

void CString::Print()
{
    cout << m_pData << endl;
}

void Test1()
{
    cout << "Test1 begin:\n" << endl;

    char * text = "Hello World";

    CString str1(text);
    CString str2;
    str2 = str1;

    str2.Print();
    cout << endl;
}

int main()
{
    Test1();
    return 0;
}


