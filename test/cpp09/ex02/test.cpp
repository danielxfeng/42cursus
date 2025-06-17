#include <gtest/gtest.h>
#include "PmergeMe.hpp"
#include "algorithm"

TEST(PairwiseComparator, Test) {
    std::vector<int> vec = {4, 7, 9, 8, 6};
    auto span = std::span<int>(vec);
    std::vector<int> out = {4, 7, 8, 9, 6};
    pairwiseComparator(vec, 2);
    EXPECT_EQ(vec, out);
    std::vector<int> vec2 = {4, 7, 8, 9, 6, 87, 53, 54};
    auto span2 = std::span<int>(vec);
    std::vector<int> out2 = {4, 7, 8, 9,   53, 54, 6, 87};
    pairwiseComparator(vec2, 4);
    EXPECT_EQ(vec2, out2);
}

TEST(mergeInsertionSortFirstPart, Test) {
    std::vector<int> vec = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    auto span = std::span<int>(vec);
    std::vector<int> out = {6, 15, 8, 16, 2, 11, 0, 17, 9, 18, 14, 19, 3, 10, 1, 21, 5, 12, 4, 20, 7, 13};
    mergeInsertionSort(vec, 1, false);
    EXPECT_EQ(vec, out);
}

TEST(mergeInsertionSortFull, Test) {
    std::vector<int> vec = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    auto span = std::span<int>(vec);
    std::vector<int> out = vec;
    std::sort(out.begin(), out.end());
    mergeInsertionSort(vec, 1, true);
    EXPECT_EQ(vec, out);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}