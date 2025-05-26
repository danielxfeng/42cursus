#pragma once
#include <algorithm>

template <typename T>
int easyfind(T &container, int n)
{
    auto it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
        return *it;
    throw std::out_of_range("not found");
}
