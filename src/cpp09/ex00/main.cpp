#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cerr << "Error: could not open file." << std::endl;
    auto bx = BitcoinExchange("/home/xifeng/42/test/cpp09/ex00/data.csv");
    bx.calculate(argv[1]);
    exit(EXIT_SUCCESS);
}