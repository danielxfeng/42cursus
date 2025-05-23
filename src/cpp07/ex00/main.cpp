#include "whatever.hpp"
#include <iostream>

int main()
{
    int a = 3;
    int b = 4;
    swap(a, b);
    std::cout << a << ";" << b << ";" << std::endl;

    std::cout << min(a, b) << std::endl;

    std::cout << max(a, b) << std::endl;
}