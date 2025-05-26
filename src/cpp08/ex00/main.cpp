#include <vector>
#include <deque>
#include <iostream>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec = {2, 3, 4, 5};
    std::cout << easyfind(vec, 3) << std::endl;
    try
    {
        std::cout << easyfind(vec, 9) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "not found" << std::endl;
    }

    std::deque<int> dq = {2, 3, 4, 5};
    std::cout << easyfind(dq, 3) << std::endl;
    try
    {
        std::cout << easyfind(dq, 9) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "not found" << std::endl;
    }
}