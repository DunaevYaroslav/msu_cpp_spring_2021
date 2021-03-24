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
    int offset;
    size_t maxSize_;
    size_t size_;
    void makeAllocator(size_t maxSize)
    {
        maxSize_ = maxSize;
        dan = new char[sizeof(size_t) * (maxSize)];
        offset = 0;
    }
    char *alloc(size_t size)
    {
        size_ = size;
        if (size + offset > maxSize_)
        {
            return nullptr;
        }
        else
        {
            mem = new char[sizeof(size_t) * (size)];
            for (int i = 0; i < size; i++)
            {
                mem[i] = dan[offset + i];
            }
        }
        return mem;
    }
    void reset()
    {
        offset = 0;
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