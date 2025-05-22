#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    /**
    ScalarConverter::convert("");
    std::cout << std::endl;
    ScalarConverter::convert("aa");
    std::cout << std::endl;
    ScalarConverter::convert("'a'");
    std::cout << std::endl;
    ScalarConverter::convert("'1'");
    std::cout << std::endl;
    ScalarConverter::convert("1");
    std::cout << std::endl;
    ScalarConverter::convert("-1");
    std::cout << std::endl;
    ScalarConverter::convert("42");
    std::cout << std::endl;
    ScalarConverter::convert("42.");
    std::cout << std::endl;
    ScalarConverter::convert("42.0");
    std::cout << std::endl;
    ScalarConverter::convert("42.f");
    std::cout << std::endl;
    ScalarConverter::convert("42f");
    std::cout << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << std::endl;
    ScalarConverter::convert("-42.0f");
    std::cout << std::endl;
    ScalarConverter::convert("42.42");
    std::cout << std::endl;
    ScalarConverter::convert("42.42f");
    std::cout << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;
    ScalarConverter::convert("+inff");
    std::cout << std::endl;
    ScalarConverter::convert("2313221313212321");
    std::cout << std::endl;
    */
     
    if (argc != 2)
    {
        std::cout << "useage: ./convert '1' or ./convert 1" << std::endl;
        exit(EXIT_FAILURE);
    }
    ScalarConverter::convert(argv[1]);
    exit(EXIT_SUCCESS);
}