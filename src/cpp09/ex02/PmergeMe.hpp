#pragma once
#include <span>
#include <vector>
#include <array>
#include <iostream>

#define ARG_MAX 147056
#define DEBUG 1

std::size_t pairwiseComparator(std::span<int> span, std::size_t pairs_group_size);
void mergeInsertionSort(std::span<int> span, std::size_t depth, bool is_insert);
std::size_t scheduler(std::span<int> span);

/**
 * @brief An implementation of merge-insertion sort
 *
 * @details
 * - Merge-insertion sort is a "MINIMUM-COMPARISON SORTING".
 *   However it's rarely used in practical.
 *
 * - Time complicity
 *   - O(n²) in total, but it has minimun comparisons:)
 *   - O(n*log(n)) in Pairwise Comparison, O(n²) in Insertion.
 * 
 * - Space complicity
 *   - O(n) in total.
 *   - O(1) in Pairwise Coparison, O(n) in Insertion.
 *
 * - The implementation:
 *   Aims to implement a Merge-insertion sort.
 *   - std::span is used to wrap the `vector` or `array`.
 * 
 * ##The merge-insertion sort##
 * 
 * We sort it as a **Tournament Tree**, implemented by an array or vector like data structure.
 *
 * ### 1. Pairwise Comparison — Building the Tree
 *
 * We recursively compare elements in pairs (log(n)):
 * - In each pair, the **larger** (the winner) moves to the next round.
 * - The **smaller** stays in place, but still carries its subtree.
 * - We maintain the invariant: (loser, winner), with subtrees swapped together.
 *
 * #### Example (Depth = 0 to 4):
 * Original input:
 *     11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7
 * 
 * The tournament tree without swapping
 * 4th:                              21
 * 3rd:                 17                          21
 * 2nd:          17            16            21            19             20
 * 1st:      11     17     16     15     10     21     18     19      12     20     13
 * 0th:    11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5,  4, 20, 13, 7
 *
 * The tournament tree with swapping
 * 
 * 4th:                              21
 * 3rd:                 17                          21
 * 2nd:          16           17             19           21              20
 * 1st:      15     16     11     17     18     19     10     21      12     20     13
 * 0th:    6, 15   8, 16  2, 11  0, 17  9, 18 14, 19  3, 10  1, 21  5, 12   4, 20  7, 13
 *
 * The final winner is 21, found at the root of the tree.
 * 
 * ### 2. Insertion Phase — Reconstructing the Sorted Array
 * We reconstruct the array layer by layer, from top to bottom (4th → 0th), then split pairs and merge sub-results.
 *
 * ### Challenge: Expanding Search Range
 * - As more elements from **pend** are inserted, the **main chain grows**, so the **search range expands**.
 * - Later insertions must search over larger portions of the chain, increasing the number of comparisons.
 *
 * ### Jacobsthal Numbers for Efficient Insertion
 * Jacobsthal numbers: [0, 1, 1, 3, 5, 11, ...]  
 * We use [1, 3, 5, 11, ...] as Jacobsthal indices.
 * - The actual insertion order: 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, ...
 *
 * - As we can use a balanced BST (binary search tree) to represent the main chain, 
 *   the sequence grows in a way that **mirrors the balanced BST expansion**.
 * - During the **Jacobsthal steps**, each pending element is inserted near its ideal position,
 *   so the **search range remains fixed and shallow**, reducing total comparison cost.
 * 
 * ### The Binary Search
 * - For example, when inserting b5, we search for its position between the start and a5 in the **main chain**.
 * - After all elements in **pend** are inserted in the correct order, the current layer becomes fully sorted.
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
     * @return the comparision times
     */
    std::size_t sort(std::vector<int> &data, std::size_t size);

    /**
     * @brief Perform an In-place Merge-insertion sort
     * @param data a container of integers
     * @param size the actual size of the array
     * @return the comparision times
     */
    std::size_t sort(std::array<int, ARG_MAX> &data, std::size_t size);
};
