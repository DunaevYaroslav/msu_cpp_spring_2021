#include <sstream>
#include "matrix.h"
#include <iostream>
#include <cassert>

void Test1(){
    Matrix m1(5, 7);
    assert(m1.getRows() == 5);
    assert(m1.getColumns() == 7); 
    for (size_t i = 0; i < m1.getRows(); i++) {
        for (size_t j = 0; j < m1.getColumns(); j++) {
            m1[i][j] = (i + 1) * (j + 1) * 2; //заполняем матрицу m1 значениями 2 4 6 ... 70
        }
    }
    int a = m1[0][0];
    assert(a == 2);
}

void Test2(){
    Matrix m1(1, 1);
    assert(m1.getRows() == 1);
    assert(m1.getColumns() == 1); 
    for (size_t i = 0; i < m1.getRows(); i++) {
        for (size_t j = 0; j < m1.getColumns(); j++) {
            m1[i][j] = 5;
        }
    }
    int a = m1[0][0];
    assert(a == 5);
}
void Test3()
{
    Matrix m(5, 9);
    assert(m.getRows() == 5);
    assert(m.getColumns() == 9);
    m[4][4] = 5; // строка 1, колонка 2

    double x = m[4][4];
    assert(x == 5);
    m *= 3; // умножение на число
    double t = m[4][4];
    assert(t==15);
}
void Test4()
{
    Matrix m1(5, 5);
    Matrix m2(5, 5);
    assert(m1 == m2);
    m1[0][0] = 5;
    assert(m1 != m2);
}
void Test5()
{
    Matrix m1(1, 1);
    Matrix m2(1, 1);
    assert(m1 == m2);
    m2 = m1 + m2;
    assert(m1 != m2);
}
void Test6()
{
    Matrix m(2, 2);
    m[1][1] = 1; 
    m[1][0] = 2;
    m[0][1] = 3;
    m[0][0] = 4; 

    assert(m[1][0] == 2);
    assert(m[0][1] == 3);
}
void Test7(){
    Matrix m1(5, 2);
    Matrix m2(2, 5);
    assert(m1 != m2);
}
void Test8(){
    Matrix m(5, 2);
    bool b = false;
    try
    {
        m[10][2] = 6;
    }
    catch(...)
    {
        b = true;
    }
    assert(b);
}
void Test9(){
    Matrix m(2, 2);
    m[0][0] = 1;
    m[0][1] = 2;
    m[1][0] = 4;
    m[1][1] = 5;
    m *= 5;
    assert(m[0][0] == 5);
    assert(m[0][1] == 10);
    assert(m[1][0] == 20);
    assert(m[1][1] == 25);
}
void Test10(){
    Matrix m1(5, 2);
    Matrix m2(2, 5);
    bool b = false;
    try
    {
        m1 = m1 + m2;
    }
    catch(...){
        b = true;
    }
    assert(b);
}

void Test11()
{
    const size_t rows = 5;
    const size_t cols = 3;
    bool flag = false;
    Matrix m(rows, cols);
    try 
    {
        m[0][7] = 100;
    }
    catch (...)
    {
        flag = true;
    }
    assert(flag);
    flag = false;
    try 
    {
        m[7][0] = 100;
    }
    catch (...)
    {
        flag = true;
    }
    assert(flag);
}
void Test12()
{
    const size_t rows = 3;
    const size_t cols = 4;

    Matrix m(rows, cols);
    m[0][1] = 1; 
    m[0][2] = 2;
    m[0][3] = 3;
    m[1][1] = 4; 
    m[1][2] = 5;
    m[1][3] = 6;
    assert(m[0][1] == 1);
    assert(m[0][2] == 2);
    assert(m[0][3] == 3);
    Matrix t(rows, cols);
    t[0][1] = 10; 
    t[0][2] = 20;
    t[0][3] = 30;
    t[1][1] = 40; 
    t[1][2] = 50;
    t[1][3] = 60;
    m = m + t;

    assert(m[0][1] == 11);
    assert(m[0][2] == 22);
    assert(m[0][3] == 33);

    m *= 2;

    assert(m[0][1] == 22);
    assert(m[0][2] == 44);
    assert(m[0][3] == 66);

}


int main() {
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
    std::cout<<"Success";
    return 0;
}