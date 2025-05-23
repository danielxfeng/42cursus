#include "iter.hpp"
#include <iostream>

void addition(int &a)
{
    a += 1;
}

int main()
{
    int arr[4] = {1, 2, 3, 4};
    iter(arr, 4, addition);
    for (size_t i = 0; i < 4; ++i)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}