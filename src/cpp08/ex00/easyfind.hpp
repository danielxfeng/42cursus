#pragma once
#include <algorithm>

template <typename T>
size_t easyfind(T &container, int n)
{
    auto it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
        return it - container.begin();
    throw std::out_of_range("not found");
}
