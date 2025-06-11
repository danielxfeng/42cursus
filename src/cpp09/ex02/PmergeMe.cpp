#include "PmergeMe.hpp"
#include <iostream>
#include <span>
#include <algorithm>
#include <cmath>

/**
 * @brief a log tool
 */
void debugInfo(std::string &msg)
{
    if (DEBUG)
        std::cout << "debug: " << msg << std::endl;
}

// --------------------------------  Constructor and Destructors of PmergeMe.
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &o) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &o) { return *this; }
PmergeMe::~PmergeMe() {}

// --------------------------------  Sorting.

/**
 * @brief To sort the container which has at most 3 elements.
 */
void easySort(std::span<int> span)
{
    if (span.size() > 3)
        throw std::runtime_error("why I am here.");
    if (span.size() < 2)
        return;
    if (span[0] > span[1])
        std::swap(span[0], span[1]);
    if (span.size() == 2)
        return;
    if (span[2] < span[0])
    {
        std::swap(span[1], span[2]);
        std::swap(span[0], span[1]);
    }
    else if (span[2] < span[1])
        std::swap(span[1], span[2]);
}

/**
 * @brief The pairwise comparator stage of sorting.
 * @details
 * Recursively applies pairwise comparison and swapping within groups of 2^depth elements.
 * Operates in-place on the provided span.
 * Unpaired elements are preserved.
 * 
 * For example:
 * Input:  [11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7]
 * Output: [6, 15, 8, 16, 2, 11, 0, 7,       9, 18, 14, 19, 3, 10, 1, 21,      5, 4, 20, 7, 13]
 */
void pairwiseComparator(std::span<int> span, std::size_t depth)
{
    // how many numbers in one "pairs group"
    const std::size_t pairs_group_size = static_cast<std::size_t>(std::pow(2, depth));
    if (pairs_group_size == 0 || pairs_group_size > span.size())
        throw std::runtime_error("why I am here.");
    
    // how many iterations we need to perform, the unpaired numbers are ignored to match the requirements.
    const std::size_t rounds = span.size() / pairs_group_size;

    const auto begin = span.begin();
    for (std::size_t i = 0; i < rounds; ++i)
    {
        // indexes of a pair: left_start, ..., left_end, right_start, ..., right end
        auto left_start = begin + i * pairs_group_size;
        auto right_start = left_start + pairs_group_size / 2;
        auto left_end = right_start - 1;
        auto right_end = right_start + pairs_group_size / 2 - 1;
        // moves the winners to the right.
        if (*(left_end) > *(right_end))
            std::swap_ranges(left_start, right_start, right_start);
    }

    // base case
    if (rounds <= 1)
        return;
    // recursive call
    return pairwiseComparator(span, depth + 1);
}

/**
 * @brief To dispatch the task based on the size of the container.
 */
void scheduler(std::span<int> span)
{
    if (span.size() < 4)
        easySort(span);
    else
        pairwiseComparator(span, 1);
}

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