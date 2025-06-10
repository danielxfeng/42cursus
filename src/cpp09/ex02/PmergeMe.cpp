#include "PmergeMe.hpp"
#include <iostream>
#include <span>

/**
 * @brief a log tool
 */
void debugInfo(std::string &msg)
{
    if (DEBUG)
        std::cout << "debug: " << msg << std::endl;
}

// Constructor and Destructors of IntView.
PmergeMe::IntView::IntView(std::span<int> span) : span_(span) {}
PmergeMe::IntView::IntView(const IntView &o) : span_(o.span_) {}
IntView &PmergeMe::IntView::operator=(const IntView &o) { span_ = o.span_; }
PmergeMe::IntView::~IntView() {}

// Constructor and Destructors of PmergeMe.
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &o) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &o) {}
PmergeMe::~PmergeMe() {}

void PmergeMe::sort(std::vector<int> &data, std::size_t size)
{
    if (size == 0)
        return;
    auto span = std::span<int>(data.data(), data.size());
    std::cout << span[0] << std::endl;
    return;
}

void PmergeMe::sort(std::array<int, ARG_MAX> &data, std::size_t size)
{
    if (size == 0)
        return;
    auto span = std::span<int>(data.data(), size);
    std::cout << span[0] << std::endl;
    return;
}