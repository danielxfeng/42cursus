#pragma once
#include <stdexcept>

template <typename T>
class Array
{
private:
    T* arr_;
    unsigned int size_;

public:
    Array() : arr_(new T[0]), size_(0) {};

    Array(unsigned int n) : arr_(new T[n]), size_(n) {};

    Array(const Array &o) : arr_(new T[o.size_]), size_(o.size_)
    {
        for (size_t i = 0; i < o.size_; ++i)
            arr_[i] = o[i];
    };

    Array &operator=(const Array &o)
    {
        if (&o == this)
            return *this;
        delete[] arr_;
        arr_ = new T[o.size_];
        for (size_t i = 0; i < o.size_; ++i)
            arr_[i] = o[i];

        size_ = o.size_;
        return *this;
    };

    ~Array()
    {
        delete[] arr_;
        size_ = 0;
    };

    const T &operator[](const unsigned int i) const
    {
        if (i >= size_)
            throw std::out_of_range("out of range");
        return arr_[i];
    };

    T &operator[](unsigned int i)
    {
        if (i >= size_)
            throw std::out_of_range("out of range");
        return arr_[i];
    }

    unsigned int size() const
    {
        return size_;
    };
};