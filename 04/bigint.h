#pragma once
#include <cstdlib>
#include <string>
#include <iomanip>

class BigInt
{
public:
    int *num_;
    bool pos_;
    int size_;
    BigInt() : num_(nullptr), pos_(true), size_(0)
    {
    }

    BigInt(const std::string &s);

    BigInt(int num);

    BigInt(const BigInt &n);

    BigInt(BigInt &&n);

    BigInt &operator=(const BigInt &n);

    BigInt &operator=(BigInt &&n);

    bool operator>(const BigInt &rhs) const;

    bool operator<(const BigInt &rhs) const;

    bool operator>=(const BigInt &rhs) const;

    bool operator<=(const BigInt &rhs) const;

    bool operator==(const BigInt &rhs) const;

    bool operator!=(const BigInt &rhs) const;

    BigInt operator-() const;

    BigInt operator+(const BigInt &rhs) const;

    BigInt operator-(const BigInt &rhs) const;

    BigInt operator*(const BigInt &rhs) const;

    ~BigInt();

    friend std::ostream &operator<<(std::ostream &os, const BigInt &n);
};
