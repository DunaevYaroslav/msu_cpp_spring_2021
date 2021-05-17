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

void TestSimpleWork1()
{
    TokenParser p;
    p.SetStartCallback(start);
    p.SetDigitTokenCallback(sum);
    p.SetStringTokenCallback(len);
    p.SetEndCallback(end);
    assert(p.Parse("123 1day ifu 7 nee6rv") == "6 4 3 7 6 ");
}

void TestSimpleWork2()
{
    TokenParser p1;
    p1.SetStartCallback(start);
    p1.SetDigitTokenCallback(sum);
    p1.SetStringTokenCallback(len);
    p1.SetEndCallback(end);
    assert(p1.Parse("fuh 48 djf6 55h 8") == "3 12 4 3 8 ");
}

void TestOnlyString()
{
    TokenParser p2;
    std::string stringTest = "Text";
    assert(p2.Parse(stringTest) == "Text");
}
void TestOneSymbol()
{
    TokenParser p3;
    p3.SetStartCallback(start);
    p3.SetDigitTokenCallback(sum);
    p3.SetStringTokenCallback(len);
    p3.SetEndCallback(end);
    assert(p3.Parse("1") == "1 ");
    assert(p3.Parse("a") == "1 ");
    assert(p3.Parse(" ") == "");
}
void TestTwoParse()
{
    TokenParser p4;
    p4.SetStartCallback(start);
    p4.SetDigitTokenCallback(sum);
    p4.SetStringTokenCallback(len);
    p4.SetEndCallback(end);
    assert(p4.Parse("123 1day ifu 7 nee6rv") == "6 4 3 7 6 ");
    assert(p4.Parse("fuh 48 djf6 55h 8") == "3 12 4 3 8 ");
}
void TestBoundary()
{
    TokenParser p5;
    p5.SetStartCallback(start);
    p5.SetDigitTokenCallback(sum);
    p5.SetStringTokenCallback(len);
    p5.SetEndCallback(end);
    assert(p5.Parse("18446744073709551615") == "87 ");//это 2^64 - 1
    assert(p5.Parse("18446744073709551616") == "20 ");//это 2^64 
    assert(p5.Parse("18446744073709551616842394") == "26 ");
}
void TestEmpty()
{
    TokenParser p6;
    p6.SetStartCallback(start);
    p6.SetDigitTokenCallback(sum);
    p6.SetStringTokenCallback(len);
    p6.SetEndCallback(end);
    std::string stringTest = "";
    assert(p6.Parse(stringTest) == "");
}

int main()
{
    TestSimpleWork1();
    TestSimpleWork2();
    TestOnlyString();
    TestOneSymbol();
    TestTwoParse();
    TestBoundary();
    TestEmpty();
    std::cout << "Success \n";
    return 0;
}
