#pragma once
#include <span>
#include <vector>
#include <array>
#include <iostream>

#define ARG_MAX 147056
#define DEBUG 1

void pairwiseComparator(std::span<int> span, std::size_t depth);

/**
 * @brief An implementation of merge-insertion sort
 *
 * @details
 * - Merge-insertion sort is a "MINIMUM-COMPARISON SORTING".
 *   However it's rarely used in practical.
 *
 * - The implementation:
 *   Aims to implement a Merge-insertion sort.
 *   - std::span is used to wrap the `vector` or `array`.
 *
 */
class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &o);
    PmergeMe &operator=(const PmergeMe &o);
    ~PmergeMe();

    /**
     * @brief Perform a In-place Merge-insertion sort
     * @param data a container of integers.
     */
    void sort(std::vector<int> &data, std::size_t size);

    /**
     * @brief Perform an In-place Merge-insertion sort
     * @param data a container of integers
     * @param size the actual size of the array
     */
    void sort(std::array<int, ARG_MAX> &data, std::size_t size);
};
