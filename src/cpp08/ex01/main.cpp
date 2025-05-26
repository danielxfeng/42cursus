#include <vector>
#include <iostream>
#include <limits>
#include "Span.hpp"

int main()
{

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

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
    try
    {
        span.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}