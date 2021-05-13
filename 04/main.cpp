#include <sstream>
#include "bigint.h"
#include <iostream>
#include <cassert>

void Test1()
{
    BigInt a;
    BigInt b;
    a = BigInt(1'000);
    b = -BigInt(1'000);
    BigInt t = a * b;
    assert(t == -1'000'000);
}
void Test2()
{
    BigInt a("11");
    BigInt b("12");

    BigInt c1(a + b);
    BigInt c2 = 23;
    assert(c1 == c2);
}
void Test3()
{
    BigInt a("11");
    std::ostringstream oss1;
    oss1 << a;
    assert(oss1.str() == "11");
}

void Test4()
{
    BigInt a("11");
    BigInt b("12");
    BigInt d = a * 2 + b;
    std::ostringstream oss2;
    oss2 << -d;
    assert(oss2.str() == "-34");
}

void Test5()
{
    BigInt a("11");
    BigInt b("12");
    a = -b;
    assert(a + b == 0);
}

void Test6()
{
    BigInt big_n("999999999999999999999999999999");
    big_n = big_n + 1;
    std::ostringstream oss3;
    oss3 << big_n;
    assert(oss3.str() == "1000000000000000000000000000000");
}

void Test7()
{
    BigInt a = BigInt(1'000);
    BigInt b = -BigInt(1'000);
    BigInt t = a * b;
    assert(t == -1'000'000);
}

void Test8()
{
    BigInt N1 = 30123;
    BigInt N2("30123");
    BigInt N3;

    assert(N1 == N2);
    assert(N1 != (-N2));
    assert(N1 > N3);
    assert((-N1) < N3);
    assert(N1 >= N2);
    assert(N1 <= (N2 + N1));
}
void Test9()
{
    BigInt N1 = 120;
    BigInt N2 = 10;
    N2 = N2 + N1;
    assert(N2 == 130);
}
void Test10()
{
    BigInt N1 = 4321;
    BigInt N2;
    BigInt N3;
    N2 = N1;
    BigInt N4 = std::move(N1);
    N3 = std::move(N2);
    assert(N4 == N3);
}
void Test11()
{
    BigInt N1("182932829848393823041577457747547754");
    BigInt N2("366463672723823919757655560929389858");
    BigInt N3;
    N3 = N1 + N2;
    assert(N3 == BigInt("182932829848393823041577457747547754") + BigInt("366463672723823919757655560929389858"));
}
void Test12()
{
    BigInt N1 = -4321;
    BigInt N2 = 4321;
    BigInt N3;
    N3 = N1 + N2;
    assert(N3 == 0);
}
void Test13()
{
    BigInt N1 = 0;
    BigInt N2 = 2;
    BigInt N3;
    N3 = N1 * N2;
    assert(N3 == 0);
}
void Test14()
{
    BigInt N1 = BigInt("-5000000000");
    BigInt N2 = BigInt("20000000000");
    BigInt N3;
    N3 = N1 * N2;
    assert(N3 == BigInt("-5000000000") * BigInt("20000000000"));
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();
    Test13();
    Test14();
    std::cout << "Success \n";
    return 0;
}