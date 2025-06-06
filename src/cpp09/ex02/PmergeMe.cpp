#include "PmergeMe.hpp"
#include <iostream>
#include <span>

std::vector<int> PmergeMe::sort(std::vector<int> &data, std::size_t size)
{
    if (size == 0)
        return data;
    auto span = std::span<int>(data.data(), data.size());
    std::cout << span[0] << std::endl;
    return data;
}

std::array<int, ARG_MAX> PmergeMe::sort(std::array<int, ARG_MAX> &data, std::size_t size)
{
    auto span = std::span<int>(data.data(), size);
    std::cout << span[0]  << std::endl;
    return data;
}