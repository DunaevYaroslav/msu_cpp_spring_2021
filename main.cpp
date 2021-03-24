#include <iostream>
using namespace std;

size_t allocated_size(void *ptr)
{
    return ((size_t *)ptr)[-1];
}

class Allocator
{
public:
    char *dan;
    char *mem;
    int maxSize_;
    int size_;
    void makeAllocator(size_t maxSize)
    {
        maxSize_ = maxSize;
        dan = new char[sizeof(size_t) * (maxSize)];
    }
    char *alloc(size_t size)
    {
        size_ = size;
        if (size > maxSize_)
        {
            return nullptr;
        }
        else
        {
            mem = (char *)realloc(dan, size);
        }
        return mem;
    }
    void reset()
    {
        delete[] dan;
    }
};

int main()
{
    Allocator t;
    size_t s = 1050000;
    size_t c = 9;
    t.makeAllocator(s);
    t.alloc(c);
    cout << allocated_size(&t.dan);
    return 0;
}