#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(EXIT_FAILURE);
    }
    try {
        auto bx = BitcoinExchange("data.csv");
        bx.calculate(argv[1]);
    } catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}