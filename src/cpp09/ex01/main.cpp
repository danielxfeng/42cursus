#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto rpn = RPN();
    try
    {
        int res = rpn.calculate(argv[1]);
        std::cout << res << std::endl;
        exit(EXIT_SUCCESS);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << "Error" << std::endl;
        exit(EXIT_FAILURE);
    }
}