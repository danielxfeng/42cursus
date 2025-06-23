#include "PmergeMe.hpp"
#include "SpanSlice.hpp"
#include <iostream>
#include <span>
#include <unordered_map>
#include <algorithm>
#include <ranges>
#include <cmath>

// Jacobsthal Numbers
constexpr int JacobsthalNumbers[17] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381};
const std::span<const int> JN(JacobsthalNumbers);

std::size_t count = 0;

// There is a index convertion, JN 3 points to b3, but the `pend`[0] points to b2, so i = JN - 2.
std::size_t jnToPendIdx(std::size_t jn_idx)
{
    if (jn_idx < 2)
        throw std::runtime_error("why I am here");
    return jn_idx - 2;
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
        ++count;
        // moves the winners to the right.
        if (*(left_end) > *(right_end))
            std::swap_ranges(left_start, right_start, right_start);
    }

    return rounds;
}

bool compare(const SpanSlice &s1, const SpanSlice &s2)
{
    ++count;
    return s1.back() < s2.back();
}

void insert(std::span<int> span, std::size_t pair_size)
{
    // create the sub-spans
    std::vector<SpanSlice> slices;
    const std::size_t size = span.size() / pair_size;
    for (std::size_t i = 0; i < size; ++i)
        slices.push_back(SpanSlice(span, i * pair_size, pair_size));

    // split to main_chain and pend, and create a hashmap map to speed up the searching.
    std::vector<SpanSlice> main_chain;
    main_chain.reserve(size);
    std::vector<SpanSlice> pend;
    for (size_t i = 0; i < size; ++i) // [b1, a1, b2, a2 ...], main chain [b1, a1, a2...], pend [b2...]
    {
        if (i == 0 || i % 2 == 1)
            main_chain.push_back(slices[i]);
        else
            pend.push_back(slices[i]);
    }

    // Apply Jacobsthal Numbers
    // we start from the 2nd one.
    for (auto it = (JN.begin() + 1); it != JN.end(); ++it)
    {
        const auto prev = it - 1;
        // Shortcut path, for JN number [3, 5], if pend.size() <= 2, we can break the loop.
        if (pend.size() <= jnToPendIdx(*prev + 1))
            break;

        // This is how to decide the end sign of iteration.
        // When we perform **b3**, the end target is **a3**, the **a3** is at main_chain[3] (b1, a1, a2, a3),
        // because we compared them in pairwise stage.
        // When we perfrom **b2**, the end target is **a2**, the end sign is at main_chain[3] for worst case (b1, b3, a1, a2),
        // because when we move from a3 to a2, b3 may also be inserted.
        // When we perfrom **b7**, then end sign is at main[9] (b1, a1, b2, a2, b3, a3, a4, a5, a6, a7)
        std::size_t search_end_index = std::min(static_cast<std::size_t>(*it + *prev - 1), static_cast<std::size_t>(main_chain.size()));
        auto main_chain_end = main_chain.begin() + search_end_index;

        for (std::size_t i = *it; i > *prev; --i)
        {
            const std::size_t pend_idx = jnToPendIdx(i);
            // For prev example, if pend.size() = 3, and JN number is 5, we need to skip the first iter.
            if (pend.size() - 1 < pend_idx)
                continue;

            const auto &pend_item = pend[pend_idx];


            // rotate the original span to re-order the sorted pend item.
            std::size_t start;
            std::size_t middle;
            std::size_t end;

            // binary search
            const auto pos_main_chain = std::lower_bound(main_chain.begin(), main_chain_end, pend_item, [](const SpanSlice &s1, const SpanSlice &s2)
                                                         { return compare(s1, s2); });

            if (pos_main_chain == main_chain.end()) // special case: pos is at the end.
            {

                start = pend_item.getIdx();
                middle = start + pair_size;
                end = main_chain.back().getIdx() + pair_size;
                if (start < middle && middle < end)
                    std::rotate(pend_item.begin(), pend_item.end(), main_chain.back().end());
            }
            else if (pend_item.begin() < (*pos_main_chain).begin())
            {
                start = pend_item.getIdx();
                middle = pend_item.getIdx() + pair_size;
                end = (*pos_main_chain).getIdx();
                if (start < middle && middle < end)
                    std::rotate(pend_item.begin(), pend_item.end(), (*pos_main_chain).begin());
            }
            else
            {
                start = (*pos_main_chain).getIdx();
                middle = pend_item.getIdx();
                end = pend_item.getIdx() + pair_size;
                if (start < middle && middle < end)
                    std::rotate((*pos_main_chain).begin(), pend_item.begin(), pend_item.end());
            }

            if (start < middle && middle < end)
            {
                SpanSlice::syncIndex(main_chain, start, middle, end);
                SpanSlice::syncIndex(pend, start, middle, end);
            }

            // rotate the main_chain to insert the sorted pend item.
            main_chain.push_back(pend[pend_idx]);
            std::rotate(pos_main_chain, main_chain.end() - 1, main_chain.end());
        }
    }
}

void mergeInsertionSort(std::span<int> span, std::size_t depth, bool is_insert)
{
    // how many numbers in one "pairs group"
    const std::size_t pairs_group_size = static_cast<std::size_t>(std::pow(2, depth));
    if (pairs_group_size == 0 || pairs_group_size > span.size())
        throw std::runtime_error("why I am here.");

    // applies the
    const auto rounds = pairwiseComparator(span, pairs_group_size);

    // recursive call
    if (rounds > 1)
        mergeInsertionSort(span, depth + 1, is_insert);

    // performs insertion
    if (is_insert)
    {
        insert(span, pairs_group_size / 2);
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
    {
        mergeInsertionSort(span, 1, true);
    }
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