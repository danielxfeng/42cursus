#pragma once
#include <span>
#include <vector>
#include <array>
#include <iostream>

#define ARG_MAX 147056

/**
 * @brief An implementation of merge-insertion sort
 *
 * @details
 * - Merge-insertion sort is a "MINIMUM-COMPARISON SORTING".
 *   However it's rarely used in pratical.
 *
 * - The implementation:
 *   Aims to implement a Merge-insertion sort, to reach the  O(n log n) time, and O(n) space.
 *   - std::span is used to avoid the unneccessary copy.
 *
 */
class PmergeMe
{
public:
    PmergeMe() = delete;
    PmergeMe(const PmergeMe &o) = delete;
    PmergeMe &operator=(const PmergeMe &o) = delete;
    ~PmergeMe() = delete;

    /**
     * @brief Perform a Merge-insertion sort
     * @param data a rvalue of integers container
     * @returns the sorted data (moved).
     */
    static std::vector<int> sort(std::vector<int> &&data, std::size_t size);

    /**
     * @brief Perform a Merge-insertion sort
     * @param data a rvalue of integers container
     * @param size the actual size of the array
     * @returns the sorted data (moved).
     */
    static std::array<int, ARG_MAX> sort(std::array<int, ARG_MAX> &&data, std::size_t size);
};
