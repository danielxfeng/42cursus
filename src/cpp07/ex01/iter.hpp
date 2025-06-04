#pragma once
#include <cstddef>

template <typename T>
void iter(T *ptr, size_t len, void (*func)(T &))
{
    for (size_t i = 0; i < len; ++i)
        func(ptr[i]);
}

template <typename T>
void iter(T *ptr, size_t len, void (*func)(const T &))
{
    for (size_t i = 0; i < len; ++i)
        func(ptr[i]);
}