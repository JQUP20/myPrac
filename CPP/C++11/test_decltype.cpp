/*
 * C++11特性：decltype关键字
decltype简介
我们之前使用的typeid运算符来查询一个变量的类型，这种类型查询在运行时进行。RTTI机制为每一个类型产生一个type_info类型的数据，而typeid查询返回的变量相应type_info数据，通过name成员函数返回类型的名称。同时在C++11中typeid还提供了hash_code这个成员函数，用于返回类型的唯一哈希值。RTTI会导致运行时效率降低，且在泛型编程中，我们更需要的是编译时就要确定类型，RTTI并无法满足这样的要求。编译时类型推导的出现正是为了泛型编程，在非泛型编程中，我们的类型都是确定的，根本不需要再进行推导。

而编译时类型推导，除了我们说过的auto关键字，还有本文的decltype。

decltype与auto关键字一样，用于进行编译时类型推导，不过它与auto还是有一些区别的。decltype的类型推导并不是像auto一样是从变量声明的初始化表达式获得变量的类型，而是总是以一个普通表达式作为参数，返回该表达式的类型,而且decltype并不会对表达式进行求值。

decltype用法
推导出表达式类型
    int i = 4;
    decltype(i) a; //推导结果为int。a的类型为int。
与using/typedef合用，用于定义类型。
    using size_t = decltype(sizeof(0));//sizeof(a)的返回值为size_t类型
    using ptrdiff_t = decltype((int*)0 - (int*)0);
    using nullptr_t = decltype(nullptr);
    vector<int >vec;
    typedef decltype(vec.begin()) vectype;
    for (vectype i = vec.begin; i != vec.end(); i++)
    {
        //...
    }
这样和auto一样，也提高了代码的可读性。

重用匿名类型
在C++中，我们有时候会遇上一些匿名类型，如:

struct
{
    int d ;
    doubel b;
}anon_s;
而借助decltype，我们可以重新使用这个匿名的结构体：

decltype(anon_s) as ;//定义了一个上面匿名的结构体
泛型编程中结合auto，用于追踪函数的返回值类型
这也是decltype最大的用途了。

template <typename _Tx, typename _Ty>
auto multiply(_Tx x, _Ty y)->decltype(_Tx*_Ty)
{
    return x*y;
}
decltype推导四规则
如果e是一个没有带括号的标记符表达式或者类成员访问表达式，那么的decltype（e）就是e所命名的实体的类型。此外，如果e是一个被重载的函数，则会导致编译错误。
否则 ，假设e的类型是T，如果e是一个将亡值，那么decltype（e）为T&&
否则，假设e的类型是T，如果e是一个左值，那么decltype（e）为T&。
否则，假设e的类型是T，则decltype（e）为T。
标记符指的是除去关键字、字面量等编译器需要使用的标记之外的程序员自己定义的标记，而单个标记符对应的表达式即为标记符表达式。例如：

int arr[4]
则arr为一个标记符表达式，而arr[3]+0不是。

我们来看下面这段代码：

    int i=10;
    decltype(i) a; //a推导为int
    decltype((i))b=i;//b推导为int&，必须为其初始化，否则编译错误
仅仅为i加上了()，就导致类型推导结果的差异。这是因为，i是一个标记符表达式，根据推导规则1，类型被推导为int。而(i)为一个左值表达式，所以类型被推导为int&。

通过下面这段代码可以对推导四个规则作进一步了解

    int i = 4;
    int arr[5] = { 0 };
    int *ptr = arr;
    struct S{ double d; }s ;
    void Overloaded(int);
    void Overloaded(char);//重载的函数
    int && RvalRef();
    const bool Func(int);

    //规则一：推导为其类型
    decltype (arr) var1; //int 标记符表达式

    decltype (ptr) var2;//int *  标记符表达式

    decltype(s.d) var3;//doubel 成员访问表达式

    //decltype(Overloaded) var4;//重载函数。编译错误。

    //规则二：将亡值。推导为类型的右值引用。

    decltype (RvalRef()) var5 = 1;

    //规则三：左值，推导为类型的引用。

    decltype ((i))var6 = i;     //int&

    decltype (true ? i : i) var7 = i; //int&  条件表达式返回左值。

    decltype (++i) var8 = i; //int&  ++i返回i的左值。

    decltype(arr[5]) var9 = i;//int&. []操作返回左值

    decltype(*ptr)var10 = i;//int& *操作返回左值

    decltype("hello")var11 = "hello"; //const char(&)[9]  字符串字面常量为左值，且为const左值。


    //规则四：以上都不是，则推导为本类型

    decltype(1) var12;//const int

    decltype(Func(1)) var13=true;//const bool

    decltype(i++) var14 = i;//int i++返回右值
这里需要提示的是，字符串字面值常量是个左值，且是const左值，而非字符串字面值常量则是个右值。
这么多规则，对于我们写代码的来说难免太难记了，特别是规则三。我们可以利用C++11标准库中添加的模板类is_lvalue_reference来判断表达式是否为左值：

    cout << is_lvalue_reference<decltype(++i)>::value << endl;
结果1表示为左值，结果为0为非右值。
同样的，也有is_rvalue_reference这样的模板类来判断decltype推断结果是否为右值。

参考资料：《深入理解C++11》

 */
#include <iostream>

struct A { double x; };
const A* a = new A { 0 };

decltype(a->x) y;
decltype((a->x)) z = y;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u);

int test_decltype01()
{
    int i = 33;
    decltype(i) j = i * 2;

    std::cout << "i = " << i << ", " << "j = " << j << '\n';

    auto f = [](int a, int b) -> int
    {
        return a * b;
    };

    decltype(f) g = f;
    i = f(2, 2);
    j = g(3, 3);

    std::cout << "i = " << i << ", " << "j = " << j << '\n';

    return 0;
}

#include <string>
#include <utility>
#include <iomanip>
#include <typeinfo>
//
template<typename T1, typename T2>
auto Plus(T1&& t1, T2&& t2) -> 
decltype(std::forward<T1>(t1) +std::forward<T2>(t2))
{
    return std::forward<T1>(t1) + std::forward<T2>(t2);
}

class X
{
    friend X operator+(const X& x1, const X& x2)
    {
        return X(x1.m_data + x2.m_data);
    }

public:
    X(int data) : m_data(data) {}
    int Dump() const {  return m_data; }

private:
    int m_data;
};

int test_decltype02()
{
    int i = 4;
    std::cout << "Plus(i, 9) = " << Plus(i, 9) << std::endl;

    float dx = 4.0;
    float dy = 9.5;
    std::cout << std::setprecision(3) << "Plus(dx, dy) = " << Plus(dx, dy) << std::endl;

    std::string hello = "Hello, ";
    std::string world = "world!";
    std::cout << Plus(hello, world) << std::endl;

    X x1(20);
    X x2(22);
    X x3 = Plus(x1, x2);
    std::cout << "x3.Dump() = " << x3.Dump() << std::endl;

    return 0;
}

//返回类型后置语法  -->  auto和decltype的结合使用
template <typename T, typename U>
decltype ((*(T*)0) + (*(U*)0)) Add(T t, U u)
{
    return t + u;
}

void test_decltype03()
{
    int a = 1;
    float b = 2.0;
    auto c = Add<decltype(a + b)>(a, b);
    std::cout << "type of c ==> " << typeid(c) << "c ==> " << c << std::endl;
}



int main()
{
  //  test_decltype01();
  //  test_decltype02();
    test_decltype03();
    return 0;
}






















































































































