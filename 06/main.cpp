#include "format.h"
#include <iostream>
#include <cassert>

void TestCorrectSimpleWork1()
{
    std::string f1 = "{0} + {1} = {2}";
    assert(format(f1, 5, 6, 11) == "5 + 6 = 11");
}
void TestCorrectSimpleWork2()
{
    std::string f2 = format("{1} + {1} + {1} + {1} + {1} + {1} + {1} + {1} + {1} + {1} + {1}= {0}", 110, "ten");
    assert(f2 == "ten + ten + ten + ten + ten + ten + ten + ten + ten + ten + ten= 110");
}

void TestWithoutSeparator()
{
    std::string f2 = format("{1}{2} = {0}", 100, 10, 0);
    assert(f2 == "100 = 100");
}

void TestExtraBracket()
{
    try
    {
        auto text = format("{1}+{{1} = {0}", 2, "one");
    }
    catch (const format_exc &err)
    {
        std::string catch_error("incorrect input");
        assert(err.what() == catch_error);
    }
}

void TestNotEnough()
{
    std::string f1 = "{0} + {1} = {2}";
    try
    {
        format(f1, 5, 6);
    }
    catch (const format_exc &re)
    {
        std::string s = re.what();
        assert(s == "Not enough arguments");
    }
}

void TestTooMany()
{
    std::string f1 = "{0} + {1} = {2}";
    try
    {
        format(f1, 5, 6, 11, 12);
    }
    catch (const format_exc &re)
    {
        std::string s = re.what();
        assert(s == "incorrect input");
    }
}

void TestStringInsteadInt()
{
    std::string f1 = "{0} + {1} = {2}";
    try
    {
        format("{error} {0} {1}", 5, 6, 7);
    }
    catch (const format_exc &re)
    {
        std::string s = re.what();
        assert(s == "incorrect input");
    }
}

void TestStringWithInt()
{
    std::string f2 = "Today is {3}. Current time is {0}:{1}. Current year is {2}.";
    assert(format(f2, 19, 30, 2020, "Tuesday") == "Today is Tuesday. Current time is 19:30. Current year is 2020.");
}

void TestStringInsteadDouble()
{
    std::string f3 = "{1} / {2} = {0}";
    assert(format(f3, "0.(3)", 1, 3) == "1 / 3 = 0.(3)");
}

void TestCopy()
{
    std::ostringstream oss;
    oss << format("{1}{0}{0}", '+', 'C');
    assert(oss.str() == "C++");
}
void TestEmptyBrackets()
{
    try
    {
        auto text = format("{1}+{} = {0}", 2, "one");
    }
    catch (const format_exc &err)
    {
        std::string catch_error("incorrect input");
        assert(err.what() == catch_error);
    }
}

void TestMixIntStr()
{
    try
    {
        auto text = format("{1}+{12one} = {0}", 2, "one");
    }
    catch (const format_exc &err)
    {
        std::string catch_error("incorrect input");
        assert(err.what() == catch_error);
    }
}

void TestEmpty()
{
    auto text = format("");
    assert(text == "");
}

void TestWithoutFormating()
{
    auto text = format("qwerty");
    assert(text == "qwerty");
}

void TestOneToken(){
    auto text = format("{0}", "test");
    assert(text == "test");
} 

void TestSeveralN(){
    auto text = format("{0}{0}{0}", "test");
    assert(text == "testtesttest");
} 

void TestFailStrAndInt(){
    try
    {
        auto text = format("{1}+{1one} = {0}", 210, "one");
    }
    catch (const format_exc &err)
    {
        std::string catch_error("incorrect input");
        assert(err.what() == catch_error);
    }
}

void TestBigN1(){
    try
    {
        auto text = format("{0} = {1}", "18446744073709551616", "two in 64");
    }
    catch (const format_exc &err)
    {
        std::string catch_error("incorrect input");
        assert(err.what() == catch_error);
    }
}

void TestBigN2(){
    try
    {
        auto text = format("{18446744073709551616} = {1}", 10, "two in 64");
    }
    catch (const format_exc &err)
    {
        std::string catch_error("incorrect input");
        assert(err.what() == catch_error);
    }
}

void TestBrackets(){
  try {
    auto text = format("{}{}[}{}{}{} = {0}", 2, "one");
  } catch (const format_exc &err) {
    std::string catch_error("incorrect input");
    assert(err.what() == catch_error);
  }

  try {
    auto text = format("{1}+{1}{ = {0}", 2, "one");
  } catch (const format_exc &err) {
    std::string catch_error("incorrect input");
    assert(err.what() == catch_error);
  }
    try {
    auto text = format("{0}{", 2);
  } catch (const format_exc &err) {
    std::string catch_error("expected } after {");
    assert(err.what() == catch_error);
  }
}
int main()
{
    TestCorrectSimpleWork1();
    TestCorrectSimpleWork2();
    TestNotEnough();
    TestTooMany();
    TestStringInsteadInt();
    TestStringWithInt();
    TestStringInsteadDouble();
    TestCopy();
    TestExtraBracket();
    TestEmptyBrackets();
    TestMixIntStr();
    TestEmpty();
    TestWithoutFormating();
    TestOneToken();
    TestSeveralN();
    TestFailStrAndInt();
    TestBigN1();
    TestBigN2();
    TestBrackets();
    std::cout << "Success";
    return 0;
}