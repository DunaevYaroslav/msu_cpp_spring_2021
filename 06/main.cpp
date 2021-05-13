#include "format.h"
#include <iostream>
#include <cassert>
void Test1(){
    std::string f1 = "{0} + {1} = {2}";
    assert(format(f1, 5, 6, 11) == "5 + 6 = 11");
}

void Test2(){
    std::string f1 = "{0} + {1} = {2}";
    try {
        format(f1, 5, 6);
    } catch (const format_exc &re) {
        std::string s = re.what();
        assert(s == "Not enough arguments");
    }
}
void Test3(){
    std::string f1 = "{0} + {1} = {2}";
    try {
        format(f1, 5, 6, 11, 12);
    } catch (const format_exc &re) {
        std::string s = re.what();
        assert(s == "Incorrect string format");
    }
}
void Test4(){
    std::string f1 = "{0} + {1} = {2}";
    try {
        format("{error} {0} {1}", 5, 6, 7);
    } catch (const format_exc &re) {
        std::string s = re.what();
        assert(s == "Incorrect string format");
    }
}
void Test5(){
    std::string f2 = "Today is {3}. Current time is {0}:{1}. Current year is {2}.";
    assert(format(f2, 19, 30, 2020, "Tuesday") == "Today is Tuesday. Current time is 19:30. Current year is 2020.");
}
void Test6(){
    std::string f3 = "{1} / {2} = {0}";
    assert(format(f3, "0.(3)", 1, 3) == "1 / 3 = 0.(3)");
}
void Test7(){
    std::ostringstream oss;
    oss << format("{1}{0}{0}", '+', 'C');
    assert(oss.str() == "C++");
}
int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    std::cout << "Success";
    return 0;
}
