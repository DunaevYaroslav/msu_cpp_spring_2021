#include "parser.h"
#include <cassert>
#include <iostream>
#include <string>
int start()
{
    return 5;
}

void sum(uint64_t &n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    n = sum;
}

void len(std::string &s)
{
    s = std::to_string(s.length());
}

std::string end()
{
    return "Goodbye!";
}

void Test1()
{
    TokenParser p;
    p.SetStartCallback(start);
    p.SetDigitTokenCallback(sum);
    p.SetStringTokenCallback(len);
    p.SetEndCallback(end);
    assert(p.Parse("123 1day ifu 7 nee6rv") == "6 4 3 7 6 ");
}

void Test2()
{
    TokenParser p1;
    p1.SetStartCallback(start);
    p1.SetDigitTokenCallback(sum);
    p1.SetStringTokenCallback(len);
    p1.SetEndCallback(end);
    assert(p1.Parse("fuh 48 djf6 55h 8") == "3 12 4 3 8 ");
}

void Test3()
{
    TokenParser p2;
    std::string stringTest = "Text";
    assert(p2.Parse(stringTest) == "Text");
}
void Test4()
{
    TokenParser p3;
    p3.SetStartCallback(start);
    p3.SetDigitTokenCallback(sum);
    p3.SetStringTokenCallback(len);
    p3.SetEndCallback(end);
    assert(p3.Parse("1") == "1 ");
}
void Test5()
{
    TokenParser p4;
    p4.SetStartCallback(start);
    p4.SetDigitTokenCallback(sum);
    p4.SetStringTokenCallback(len);
    p4.SetEndCallback(end);
    assert(p4.Parse("123 1day ifu 7 nee6rv") == "6 4 3 7 6 ");
    assert(p4.Parse("fuh 48 djf6 55h 8") == "3 12 4 3 8 ");
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    std::cout << "Success \n";
    return 0;
}
