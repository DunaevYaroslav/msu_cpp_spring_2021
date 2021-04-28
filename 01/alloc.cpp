#include "alloc.h"

void Allocator::makeAllocator(size_t maxSize)
{
    if (alloc_ == nullptr)
    {
        alloc_ = new char[maxSize];
    }
    else
    {
        delete[] alloc_;
        alloc_ = new char[maxSize];
    }
    offset_ = 0;
    size_ = maxSize;
};

char *Allocator::alloc(size_t size)
{
    if (offset_ + size > size_)
    {
        return nullptr;
    }
    offset_ += size;
    return alloc_ + offset_ - size;
};

void Allocator::reset()
{
    offset_ = 0;
};

Allocator::~Allocator()
{
    delete[] alloc_;
    offset_ = 0;
}
