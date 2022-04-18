#include "std_function.hpp"

void Test(const char* string)
{
    int result = my_std::StrToInt(string);
    if(result == 0 && my_std::g_nStatus == my_std::kInvalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    Test("");

    Test("123");

    Test("+123");

    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}

