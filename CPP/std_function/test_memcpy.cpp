#include "std_function.hpp"
#include <iostream>

using namespace my_std;

int main()
{
    char buf[100] = "abcdefghijk";
    Memcpy(buf+2, buf, 5);
    std::cout << buf+2 << std::endl;

    return 0;
}
