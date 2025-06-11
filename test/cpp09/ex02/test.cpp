#include <gtest/gtest.h>
#include "PmergeMe.hpp"

TEST(PairwiseComparator, Test) {
    std::vector<int> vec = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    auto span = std::span<int>(vec);
    std::vector<int> out = {6, 15, 8, 16, 2, 11, 0, 17, 9, 18, 14, 19, 3, 10, 1, 21, 5, 12, 4, 20, 7, 13};
    pairwiseComparator(vec, 1);
    EXPECT_EQ(vec, out);
}