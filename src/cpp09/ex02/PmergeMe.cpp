#include "PmergeMe.hpp"
#include <span>

// A scheduler to handle the sorting.
void scheduler(std::span<int> span);

// --------------------------------  Constructor and Destructors of PmergeMe.
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &o) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &o) { return *this; }
PmergeMe::~PmergeMe() {}

void PmergeMe::sort(std::vector<int> &data, std::size_t size)
{
    if (size == 0)
        return;
    auto span = std::span<int>(data.data(), data.size());
    scheduler(span);
    return;
}

void PmergeMe::sort(std::array<int, ARG_MAX> &data, std::size_t size)
{
    if (size == 0)
        return;
    auto span = std::span<int>(data.data(), size);
    scheduler(span);
    return;
}