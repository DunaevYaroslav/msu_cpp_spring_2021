#include <cstdlib>

class Allocator
{
private:
    char *alloc_ = nullptr;
    size_t offset_ = 0;
    size_t size_ = 0;

public:
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    ~Allocator();
};
