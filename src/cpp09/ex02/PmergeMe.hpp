#pragma once
#include <span>
#include <vector>
#include <array>
#include <iostream>

#define ARG_MAX 147056
#define DEBUG 1

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
 *   - IntView is a `slice` of a `span`.
 *
 */
class PmergeMe
{
private:
    /**
     * @brief IntView acts like the `slice` of a span.
     */
    class IntView
    {
    private:
        std::span<int> span_;

    public:
        IntView() = delete;
        IntView(std::span<int> span);
        IntView(const IntView &o);
        IntView &operator=(const IntView &o);
        ~IntView();

        std::span<int>::iterator begin() const;
        std::span<int>::iterator end() const;
    };

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
