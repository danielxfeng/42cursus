#include "PmergeMe.hpp"
#include <span>

std::size_t PmergeMe::sort(std::vector<int> &data, std::size_t size)
{
    if (size == 0)
        return 0;
    auto span = std::span<int>(data.data(), data.size());
    return scheduler(span);
}

std::size_t PmergeMe::sort(std::array<int, ARG_MAX> &data, std::size_t size)
{
    if (size == 0)
        return 0;
    auto span = std::span<int>(data.data(), size);
    return scheduler(span);
}