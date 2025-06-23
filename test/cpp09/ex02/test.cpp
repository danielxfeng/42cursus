#include <gtest/gtest.h>
#include <random>
#include "PmergeMe.hpp"
#include "algorithm"

std::vector<int> generateRandomVector(int length, int max_value)
{
    std::vector<int> vec(length);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, max_value - 1);

    std::generate(vec.begin(), vec.end(), [&]()
                  { return dist(gen); });
    return vec;
}

TEST(PairwiseComparator, Test)
{
    std::vector<int> vec = {4, 7, 9, 8, 6};
    auto span = std::span<int>(vec);
    std::vector<int> out = {4, 7, 8, 9, 6};
    pairwiseComparator(vec, 2);
    EXPECT_EQ(vec, out);
    std::vector<int> vec2 = {4, 7, 8, 9, 6, 87, 53, 54};
    auto span2 = std::span<int>(vec);
    std::vector<int> out2 = {4, 7, 8, 9, 53, 54, 6, 87};
    pairwiseComparator(vec2, 4);
    EXPECT_EQ(vec2, out2);
}

TEST(mergeInsertionSortFirstPart, Test)
{
    std::vector<int> vec = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    auto span = std::span<int>(vec);
    std::vector<int> out = {6, 15, 8, 16, 2, 11, 0, 17, 9, 18, 14, 19, 3, 10, 1, 21, 5, 12, 4, 20, 7, 13};
    mergeInsertionSort(vec, 1, false);
    EXPECT_EQ(vec, out);
}

TEST(mergeInsertionSortFull, Test)
{
    std::vector<int> vec = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    auto span = std::span<int>(vec);
    std::vector<int> out = vec;
    std::sort(out.begin(), out.end());
    mergeInsertionSort(vec, 1, true);
    EXPECT_EQ(vec, out);
}

TEST(mergeInsertionSort7, Test)
{
    std::vector<int> vec = {67, 55, 28, 1, 66, 59, 32 };
    auto span = std::span<int>(vec);
    std::vector<int> out = vec;
    std::sort(out.begin(), out.end());
    mergeInsertionSort(vec, 1, true);
    EXPECT_EQ(vec, out);
}

TEST(mergeInsertionSortFullRandom, Test)
{
    for (int i = 4; i < 30; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            std::cout << "Length: " << i << " , index: " << j << " start." << std::endl;
            
            std::vector<int> vec = generateRandomVector(i, i + 100);
            for (auto &n : vec)
            {
                std::cout << n << ", ";
            }
            std::cout << std::endl;
            auto span = std::span<int>(vec);
            std::vector<int> out = vec;
            std::sort(out.begin(), out.end());
            mergeInsertionSort(vec, 1, true);
            EXPECT_EQ(vec, out);
            std::cout << "Length: " << i << " , index: " << j << " done." << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}