#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <span>
#include <algorithm>
#include <chrono>

/**
 * @brief parses the given argv, and fill to given 2 different containers, throw on error.
 */
void parse(std::size_t size, char **argv, std::vector<int> &vec, std::array<int, ARG_MAX> &arr)
{
    std::size_t end;

    for (std::size_t i = 0; i < size; ++i)
    {
        try
        {
            int n = std::stoi(argv[i + 1], &end);  // argv starts from 1
            if (argv[i + 1][end] != '\0' || n < 0) // check end of the int, or value is not positive
                throw std::invalid_argument("illegal argument");
            vec.push_back(n);
            arr[i] = n;
        }
        catch (std::exception &e)
        {
            throw std::invalid_argument("parsing error");
        }
    }
}

/**
 * @brief calls cout to print out the given container.
 */
void output(const auto &data, std::size_t size)
{
    std::for_each(data.begin(), data.begin() + size, [](const int &n)
                  { std::cout << n << " "; });
    std::cout << std::endl;
}

/**
 * @brief prints out the error info and exit, as required.
 */
int errorHandler()
{
    std::cerr << "Error" << std::endl;
    return EXIT_FAILURE;
}

/**
 * @brief prints out the timestamp as required.
 */
void printTs(std::size_t size, std::string container, double duration)
{
    std::cout << "Time to process a range of " << size << " elements with std::[" << container << "] : " << duration << " us" << std::endl;
}

/**
 * @brief checks 2 containers, throw when the elements are not matched, or the elements are not proper sorted.
 */
void resultCheck(const std::vector<int> &vec, const std::array<int, ARG_MAX> &arr, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        if (vec[i] != arr[i]                             // value in 2 containers do not equal.
            || ((i != size - 1) && vec[i] > vec[i + 1])) // curr > next
            throw std::runtime_error("unmatched result");
    }
}

/**
 * @brief calls sorter to sort the data, param `data` is mutated, returns the duration of sorting.
 */
double sort(auto &data, size_t size)
{
    auto pm = PmergeMe();
    auto now = std::chrono::high_resolution_clock::now();
    pm.sort(data, size);
    std::chrono::duration<double, std::micro> elapsed = std::chrono::high_resolution_clock::now() - now;
    return elapsed.count();
}

int main(int argc, char **argv)
{
    if (argc == 1 || argc > ARG_MAX)
        return errorHandler();

    auto vec = std::vector<int>{};

    auto arr = std::array<int, ARG_MAX>{};

    try
    {
        // Parse the argv, throw on error.
        std::size_t size = argc - 1;
        vec.reserve(size);
        parse(size, argv, vec, arr);

        // Output the unsorted data.
        std::cout << "before: ";
        output(vec, size);

        // Sort using vector.
        auto duration_vec = sort(vec, size);

        // Output the sorted data.
        std::cout << "after:  ";
        output(vec, size);

        // Sort using array.
        auto duration_arr = sort(arr, size);

        // Print the ts as required.
        printTs(size, "vector", duration_vec);
        printTs(size, "array", duration_arr);

        // Check the result, may throw.
        resultCheck(vec, arr, size);
    }
    catch (std::invalid_argument &e)
    {
        return errorHandler();
    }
}