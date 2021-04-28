#include <iostream>
#include "alloc.h"
#include <cassert>

using namespace std;

void DefaultWorkTest()
{
    Allocator alloc;
    alloc.makeAllocator(15);
    assert(nullptr != alloc.alloc(3));
    assert(nullptr != alloc.alloc(7));
    assert(nullptr != alloc.alloc(4));
    alloc.reset();
    assert(nullptr != alloc.alloc(8));
    assert(nullptr != alloc.alloc(4));
}

void IntLimitTest()
{
    Allocator alloc;
    alloc.makeAllocator(4);
    assert(nullptr != alloc.alloc(2));
    assert(nullptr == alloc.alloc(8));
    alloc.reset();
    assert(nullptr == alloc.alloc(11));
}

void NegativeTest()
{
    Allocator alloc;
    assert(nullptr == alloc.alloc(100));
    alloc.makeAllocator(1);
    assert(nullptr != alloc.alloc(1));
}

void TestCheckBlockAlloc()
{
    Allocator alloc;
    alloc.makeAllocator(6);
    assert(nullptr != alloc.alloc(4));
    assert(nullptr == alloc.alloc(5));
    assert(nullptr != alloc.alloc(1));
    assert(nullptr == alloc.alloc(3));
}

int main()
{   
    DefaultWorkTest();
    IntLimitTest();
    NegativeTest();
    TestCheckBlockAlloc();
    
    cout << "Success \n";
    return 0;
}
