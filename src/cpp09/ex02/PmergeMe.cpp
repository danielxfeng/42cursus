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
 * Applies pairwise comparison for the span, and swapping within the pairs_group.
 * Operates in-place on the provided span.
 *
 * For example:
 * Input:  [4, 7, 9, 8, 6], 2
 * Output: [4, 7,   8, 9,   6]
 *
 * Input:  [4, 7, 8, 9, 6, 87, 53, 54], 4
 * Output: [4, 7, 8, 9,   53, 54, 6, 87]
 *
 * @param span The int span to sort
 * @param pairs_group_size The size of a pair of numbers
 *
 * @return How many rounds of the comparasion
 */
std::size_t pairwiseComparator(std::span<int> span, std::size_t pairs_group_size)
{
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

    return rounds;
}

void insertBack()
{
    return;
}

void mergeInsertionSort(std::span<int> span, std::size_t depth, bool is_insert = true)
{
    // how many numbers in one "pairs group"
    const std::size_t pairs_group_size = static_cast<std::size_t>(std::pow(2, depth));
    if (pairs_group_size == 0 || pairs_group_size > span.size())
        throw std::runtime_error("why I am here.");

    const auto rounds = pairwiseComparator(span, pairs_group_size);

    // recursive call
    if (rounds > 1)
        return mergeInsertionSort(span, depth + 1);

    // todo
    if (is_insert)
        insertBack();
}

// Generates a Jacobsthal Numbers without the first 2 elements.
void customJacobsthalNumbers(int arr[], std::size_t size)
{
    int j0 = 0;
    int j1 = 1;
    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = j1 + 2 * j0;
        j0 = j1;
        j1 = arr[i];
    }
}

/**
 * @brief To dispatch the task based on the size of the container.
 */
void scheduler(std::span<int> span)
{
    if (span.size() < 4)
        easySort(span);
    else
        mergeInsertionSort(span, 1);
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