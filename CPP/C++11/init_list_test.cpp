//初始化列表
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

struct Foo {
    std::vector<int> mem = {1, 2, 3};
    std::vector<int> mem2;
    Foo() : mem2{ -1, -2, -3 } {}
};

std::pair<std::string, std::string> f(std::pair<std::string, std::string> p)
{
    return { p.second, p.first };
}

int test_init_list01()
{
    int n0{};
    int n1{ 1 };
    std::string s1{'a', 'b', 'c', 'd'};
    std::string s2{ s1, 2, 2 };
    std::string s3{ 0x61, 'a' };

    int n2 = { 1 };
    double d = double{ 1.2 };

    std::map<int , std::string> m = {
        {1, "a"},
        {2, {'a', 'b', 'c'} },
        {3, s1 }
    };

    std::cout << f({"hello", "world" }).first << '\n';

    const int(&ar)[2] = { 1, 2};
    int&& r1 = { 1 };

    unsigned char uc1{ 10 };

    Foo f;

    std::cout << n0 << ' ' << n1 << ' ' << n2 << '\n' << s1 << ' ' << s2 << ' ' << s3 << '\n';

    for(auto p : m)
        std::cout << p.first << ' ' << p.second << '\n';

    for(auto n : f.mem)
        std::cout << n << ' ';
    for(auto n : f.mem2)
        std::cout << n << ' ';

    return 0;
}

int test_init_list02()
{
    int arr[]       {1, 2, 3, 4, 5};
    std::vector<int> v{1, 2, 3, 4, 5 };
    std::set<int> s{ 1, 2, 3, 4, 5 };
    std::map<int, std::string> m{ {0, "zero"}, {1, "one"}, {2, "two"} };

    for(auto i : arr)
        std::cout << i << " ";
    std::cout << std::endl;

    for(auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    for(auto i : s)
        std::cout << i << " ";
    std::cout << std::endl;

    for(auto& v : m)
        std::cout << v.first << " " << v.second << " ";
    std::cout << std::endl;

    return 0;
}

//
struct ClassA {
    int x;
    double y;
};


class ClassB {
private:
    int x;
    double y;

public:
    ClassB(int _x, double _y) : x(_x), y(_y) {}
};

std::pair<double, double> multiplyVectors(
    std::pair<double, double> v1,
    std::pair<double, double> v2) {
    return { v1.first*v2.first, v1.second*v2.second };
}

int test_init_list03()
{
    int i{ 3 };
    int j{};
    std::string s{"hello"};

    ClassA objA1{};
    ClassA objA2{1, 2.0};
    ClassB objB1{1, 2.0};
    ClassA arrOfAs[] = { {1, 1.0}, {2, 2.0}, {3, 3.0} };
    for(auto i : arrOfAs)
        std::cout << i.x << " " << i.y << " ";

    ClassB arrOfBs[] = { {1, 1.0}, {2, 2.0}, {3, 3.0} };

    std::vector<ClassB> vectorOfBs = { {1, 1.0}, {2, 2.0}, {3, 3.0} };

    auto result = multiplyVectors({ 1.0, 2.0 }, { 3.0, 4.0 });
    for(auto i : result)
        std::cout << i.first << " " << i.second << " ";

    return 0;

}

int main()
{
    //test_init_list01();
    //test_init_list02();
    test_init_list03();
    return 0;
}

