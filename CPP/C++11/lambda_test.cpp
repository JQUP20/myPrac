/*
 *Ｃ++11 学习笔记 lambda表达式

　　lambda表达式是C++11最重要也最常用的一个特性之一。lambda来源于函数式编程的概念，也是现代编程语言的一个特点。

 

一.函数式编程简介

定义：简单说，“函数式编程”是一种“编程范式”。它属于“结构化编程”的一种，主要思想是把运算过程尽量写成一系列嵌套的函数调用。

 

特点：

1).函数是“第一等公民”，可以赋值给他其他变量，也可以做为参数，返回值。

2).只用“表达式”，不用“语句”。“表达式”是一个单纯的运算过程，总是有返回值；“语句”是执行某种操作，没有返回值。

3).没有副作用。函数保持独立，所有功能就是返回一个新的值，其他什么都不做，不修改外部变量的值。

4).引用透明。函数的运行不依赖于外部变量或“状态”，只依赖于输入的参数，只要参数相同，返回值就相同。

 

二.lambda表达式

lambda表达式有如下优点：

1).声明式编程风格:就地匿名定义目标函数或函数对象，不需要额外写一个命名函数或者函数对象。以更直接的方式去写程序，好的可读性和可维护性。

2).简洁：不需要额外再写一个函数或者函数对象，避免了代码膨胀和功能分散，让开发者更加集中精力在手边的问题，同时也获取了更高的生产率。

3).在需要的时间和地点实现功能闭包，使程序更灵活。

 

lambda表达式的语法归纳如下：

[ caputrue ] ( params ) opt -> ret { body; };

1).capture是捕获列表；

2).params是参数表；(选填)

3).opt是函数选项；可以填mutable,exception,attribute（选填）

mutable说明lambda表达式体内的代码可以修改被捕获的变量，并且可以访问被捕获的对象的non-const方法。

exception说明lambda表达式是否抛出异常以及何种异常。

attribute用来声明属性。

4).ret是返回值类型。(选填)

5).body是函数体。

 

捕获列表：lambda表达式的捕获列表精细控制了lambda表达式能够访问的外部变量，以及如何访问这些变量。

1).[]不捕获任何变量。

2).[&]捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）。

3).[=]捕获外部作用域中所有变量，并作为副本在函数体中使用(按值捕获)。

4).[=,&foo]按值捕获外部作用域中所有变量，并按引用捕获foo变量。

5).[bar]按值捕获bar变量，同时不捕获其他变量。

6).[this]捕获当前类中的this指针，让lambda表达式拥有和当前类成员函数同样的访问权限。如果已经使用了&或者=，就默认添加此选项。捕获this的目的是可以在lamda中使用当前类的成员函数和成员变量。

 class A
 {
 public:
     int i_ = 0;
     
     void func(int x,int y){
         auto x1 = [] { return i_; };                             //error,没有捕获外部变量
         auto x2 = [=] { return i_ + x + y; };               //OK
         auto x3 = [&] { return i_ + x + y; };               //OK
         auto x4 = [this] { return i_; };                        //OK
         auto x5 = [this] { return i_ + x + y; };            //error,没有捕获x,y
         auto x6 = [this, x, y] { return i_ + x + y; };    //OK
         auto x7 = [this] { return i_++; };                   //OK
 };
 
 int a=0 , b=1;
 auto f1 = [] { return a; };                            //error,没有捕获外部变量    
 auto f2 = [&] { return a++ };                      //OK
 auto f3 = [=] { return a; };                         //OK
 auto f4 = [=] {return a++; };                     //error,a是以复制方式捕获的，无法修改
 auto f5 = [a] { return a+b; };                     //error,没有捕获变量b
 auto f6 = [a, &b] { return a + (b++); };      //OK
 auto f7 = [=, &b] { return a + (b++); };     //OK


 注意的细节：

1.

　　一个容易出错的细节是lambda表达式的延迟调用，lambda表达式按值捕获了所有外部变量。在捕获的一瞬间，a的值就已经被复制了。如果希望lambda表达式在调用时能即时访问外部变量，我们应当使用引用方式捕获。

 int a = 0;
 auto f = [=] { return a; };
 
 a+=1;
 
 cout << f() << endl;       //输出0
 
 
 int a = 0;
 auto f = [&a] { return a; };
 
 a+=1;
 
 cout << f() <<endl;       //输出1


2.

　　虽然按值捕获的变量值均补复制一份存储在lambda表达式变量中， 修改他们也并不会真正影响到外部，但我们却仍然无法修改它们。

　　那么如果希望去修改按值捕获的外部变量，需要显示指明lambda表达式为mutable。

　　需要注意：被mutable修饰的lambda表达式就算没有参数也要写明参数列表。
　　原因：lambda表达式可以说是就地定义仿函数闭包的“语法糖”。它的捕获列表捕获住的任何外部变量，最终均会变为闭包类型的成员变量。按照C++标准，lambda表达式的operator()默认是const的，一个const成员函数是无法修改成员变量的值的。而mutable的作用，就在于取消operator()的const。

int a = 0;
auto f1 = [=] { return a++; };                       //error
auto f2 = [=] () mutable { return a++; };       //OK

3.

　　没有捕获变量的lambda表达式可以直接转换为函数指针，而捕获变量的lambda表达式则不能转换为函数指针。原因可以参考2中的原因。

typedef void(*Ptr)(int*);
 
Ptr p = [](int* p) { delete p; };              //OK
Ptr p1 = [&] (int* p) { delete p; };         //error


最后，两个实际应用到lambda表达式的代码。

std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
int even_count = 0;
for_each(v.begin(), v.end(), [&even_count](int val){
    if(!(val & 1)){
        ++ even_count;
    }
});
std::cout << "The number of even is " << even_count << std::endl;

int count = std::count_if( coll.begin(), coll.end(), [](int x){ return x > 10; });
 
int count = std::count_if( coll.begin(), coll.end(), [](int x){ return x < 10; });
 
int count = std::count_if( coll.begin(), coll.end(), [](int x){ return x > 5 && x<10; });
*/

#include <iostream>
#include <algorithm>
#include <functional>


/*
 * []		Capture nothing (or, a scorched earth strategy?)
	[&]		Capture any referenced variable by reference
	[=]		Capture any referenced variable by making a copy
	[=, &foo]	Capture any referenced variable by making a copy, but capture variable foo by reference
	[bar]		Capture bar by making a copy; don't copy anything else
	[this]		Capture the this pointer of the enclosing class
 */
int test_lambda1()
{
    int a = 1, b = 1, c = 1;

    auto m1 = [a, &b, &c]() mutable {
        auto m2 = [a, b, &c]() mutable {
            std::cout << a << b << c << '\n';
            a = 4; b  = 4; c = 4;
        };
        a = 3; b = 3; c = 3;
        m2();
    };

    a = 2;
    b = 2;
    c = 2;

    m1();                                   // calls m2() and print 123
    std::cout << a << b << c << '\n';       // prints 234
    
    return 0;
}

#include <vector>

int test_lambda2()
{
    std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());
    std::cout << "c: ";

    // the type of a closure cannot be named, but can be inferred with auto
    auto func1 = [](int i) { return i + 4; };
    std::cout << "func1 : " << func1(6) << '\n';

    // like all callable objects, closures can be captured in std::function
	// (this may incur unnecessary overhead)
    std::function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';

    return 0;
}

int test_lambda3()
{
    int m = 0;
    int n = 0;
    [&, n](int a) mutable { m = ++n + a; }(4);

    std::cout << m << std::endl << n << std::endl;

    return 0;
}

//
template <typename C>
void print(const std::string& s, const C& c)
{
    std::cout << s;

    for(const auto& e : c)  {
        std::cout << e << " ";
    }

    std::cout << std::endl;
}

void fillVector(std::vector<int>& v)
{
    static int nextValue = 1;

    generate(v.begin(), v.end(), [] { return nextValue++;});
}

int test_lambda4()
{
    const int elementCount = 9;
    std::vector<int> v(elementCount, 1);

    int x = 1;
    int y = 1;

    generate_n(v.begin() + 2,
        elementCount - 2,
        [=]() mutable throw() -> int{
        int n = x + y;
        x = y;
        y=  n;
        return n;
    });

    print("vectir v after call to generate_n() with lambda: ", v);

    std::cout << "x: " << x << " y: " << y << std::endl;

    fillVector(v);
    print("vector v after 1st call to fillVector(): ", v);
    
    fillVector(v);
    print("vector v after 2nd call to fillVector(): ", v);

    return 0;
}

template<typename T>
std::function<T()>  makeAccumulator(T& val, T by) {
    return [=, &val]() {
        return (val += by);        
    };
}

int test_lambda5()
{
    int val = 10;
    auto add5 = makeAccumulator(val ,5);
    std::cout << add5() << std::endl;
    std::cout << add5() << std::endl;
    std::cout << add5() << std::endl;
    std::cout << std::endl;

    val = 100;
    auto add10 = makeAccumulator(val, 10);
    std::cout << add10() << std::endl;
    std::cout << add10() << std::endl;
    std::cout << add10() << std::endl;

    return 0;
}

// reference: http://blogorama.nerdworks.in/somenotesonc11lambdafunctions/
class Foo_lambda {
public:
	Foo_lambda() {
		std::cout << "Foo_lambda::Foo_lambda()" << std::endl;
	}

	Foo_lambda(const Foo_lambda& f) {
		std::cout << "Foo_lambda::Foo_lambda(const Foo_lambda&)" << std::endl;
	}

	~Foo_lambda() {
		std::cout << "Foo_lambda~Foo_lambda()" << std::endl;
	}
};

int test_lambda6()
{
	Foo_lambda f;
	auto fn = [f]() { std::cout << "lambda" << std::endl; };
	std::cout << "Quitting." << std::endl;
	return 0;
}

//
template<typename Cal>
static void display(Cal cal)
{
    fprintf(stderr, "start\n");
    cal();
}

int test_lambda7()
{
    int num { 1 };

    auto fun = [&](){
        if(num % 5 == 0) {
            fprintf(stderr, "***** reset *****\n");
            fprintf(stderr, "num = %d\n", num);

            num = 0;
        } else {
            fprintf(stderr, "+++++ continue +++++\n");
            fprintf(stderr, "num = %d\n", num);
        }

        num++;
    };

    for(int i = 0; i < 20; i++) {
        fprintf(stderr, "======= i = %d\n", i);
        display(fun);
    }

    return 0;
}

int main()
{
//    test_lambda1();
//    test_lambda2();
//    test_lambda3();
    //test_lambda4();
    //test_lambda5();
    //test_lambda6();
    test_lambda7();

    return 0;
}











































































































