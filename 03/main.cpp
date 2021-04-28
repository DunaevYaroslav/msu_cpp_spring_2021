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

int main() {
    Test1();
    Test2();
    std::cout<<"Success";
    return 0;
}