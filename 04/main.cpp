#include <sstream>
#include "bigint.h"
#include <iostream>
#include <cassert>

void Test1(){
    BigInt a;
    BigInt b;
    a = BigInt(1000);
    b = -BigInt(1000);
    BigInt t =  a * b;
    assert(t == -1000000);
}
void Test2(){
    BigInt a("11");
    BigInt b("12");

    BigInt c1(a + b);
    BigInt c2 = 23;
    assert(c1 == c2);
}
void Test3(){
    BigInt a("11");
    std::ostringstream oss1;
    oss1 << a;
    assert(oss1.str() == "11");
}

void Test4(){
    BigInt a("11");
    BigInt b("12");
    BigInt d = a * 2 + b;
    std::ostringstream oss2;
    oss2 << -d;
    assert(oss2.str() == "-34");
}

void Test5(){
    BigInt a("11");
    BigInt b("12");
    a = -b;
    assert(a + b == 0);
}

void Test6(){
    BigInt big_n("999999999999999999999999999999");
    big_n = big_n + 1;
    std::ostringstream oss3;
    oss3 << big_n;
    assert(oss3.str() == "1000000000000000000000000000000");
}

void Test7(){
    BigInt a = BigInt(1000);
    BigInt b = -BigInt(1000);
    BigInt t =  a * b;
    assert(t == -1000000);
}
int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    return 0;
}