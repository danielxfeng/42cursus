#include <vector>
#include <iostream>
#include <limits>
#include "Span.hpp"

int main()
{
    auto span = Span();

    try
    {
        span.addNumber(3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    span = Span(2);
    span.addNumber(1);
    span.addNumber(2);
    try
    {
        span.addNumber(3);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    size_t size = 100000;
    auto min = -887;
    auto max = 100022;
    span = Span(size + 2);
    for (size_t i = 0; i < (size / 2); ++i)
        span.addNumber(i);
    span.addNumber(min);
    span.addNumber(max);
    for (size_t i = size / 2; i < size; ++i)
        span.addNumber(i);

    std::cout << span.longestSpan() << std::endl;
    std::cout << span.shortestSpan() << std::endl;

    span = Span(2);
    span.addNumber(std::numeric_limits<int>::min());
    span.addNumber(std::numeric_limits<int>::max());
    try
    {
        span.longestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << span.shortestSpan() << std::endl;
}