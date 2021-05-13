#include "serializer.h"
#include <cassert>
#include <iostream>
struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }
};

struct Err
{
    bool a;
    uint64_t b;
    uint64_t c;
    uint64_t d;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }
    
    template <class Deserializer>
    Error deserialize(Deserializer& deserializer)
    {
        return deserializer(a, b, c);
    }
};

void Test1()
{
    Data a {56, false, 78};
    Data b {56, true, 89};

    std::ostringstream oss1;
    Serializer ser1(oss1);

    if (ser1.save(a) == Error::CorruptedArchive) {
        throw std::runtime_error("Serialization failed");
    }
    if (ser1.save(b) == Error::CorruptedArchive) {
        throw std::runtime_error("Serialization failed");
    }
    uint64_t tmp1, tmp2;
    std::string tmp3;
    std::string s = oss1.str();
    std::istringstream iss1(s);
    iss1 >> tmp1 >> tmp3 >> tmp2 >> tmp2;
    assert(tmp1 == tmp2);

    assert(tmp3 == "false");
    iss1 >> tmp3;
    assert(tmp3 == "true");
}

void Test2(){
    Data a {56, false, 78};
    std::ostringstream oss1;
    uint64_t tmp1, tmp2;
    std::string s = oss1.str();
    std::ostringstream oss2;
    Serializer ser2(oss2);
    if (ser2(true, true, false, uint64_t(555), uint64_t(90), false,
            uint64_t(17), true, uint64_t(18)) == Error::CorruptedArchive) {
        throw std::runtime_error("Serialization failed");
    }

    s = oss2.str();
    std::istringstream iss2(s);
    Deserializer des(iss2);
    bool tmp4, tmp5;
    if (des(tmp4, tmp5, tmp4, tmp1, tmp2, tmp5) == Error::CorruptedArchive) {
        throw std::runtime_error("Deserialization failed");
    }
    assert(tmp4 == tmp5);
    assert(tmp4 == false);
    assert(tmp1 == 555);
    assert(tmp2 == 90);

    if (des.load(a) == Error::CorruptedArchive) {
        throw std::runtime_error("Deserialization failed");
    }
    assert(a.a == 17);
    assert(a.b == true);
    assert(a.c == 18);
}
void Test3()
{
    Data x {false, true, 111};
    
    std::stringstream stream;
    Deserializer deserializer(stream);
    
    assert(deserializer.load(x) == Error::CorruptedArchive);
}
void Test4()
{
    Data x {false, true, 123};
    Data y {false, false, 0};
    
    std::stringstream stream;
    Serializer serializer(stream);
    Deserializer deserializer(stream);
    
    assert(serializer.save(x)   == Error::NoError);
    assert(deserializer.load(y) == Error::NoError);
    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
}
void Test5()
{
    Data x {false, true, 123};
    
    std::stringstream stream;
    Serializer serializer(stream);
    
    assert(serializer.save(x) == Error::NoError);
}

void Test6()
{
    Data x {false, true, 123};
    Err y {false, 0, 0, 14};
    
    std::stringstream stream;
    Serializer serializer(stream);
    Deserializer deserializer(stream);
    
    assert(serializer.save(x)   == Error::NoError);
    assert(deserializer.load(y) == Error::CorruptedArchive);
}


int main() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    std::cout << "Success\n";
}
