#include "Span.hpp"
#include <iostream>
#include <limits>
#include <algorithm>

Span::Span() : max_(0) {}
Span::Span(unsigned int max) : max_(max) { container_.reserve(max); }
Span::Span(const Span &o) : container_(o.container_), max_(o.max_) {}
Span &Span::operator=(const Span &o)
{
    container_ = o.container_;
    max_ = o.max_;
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n)
{
    if (container_.size() >= max_)
        throw std::out_of_range("the container is full.");
    container_.push_back(n);
}

int Span::minMaxSpan(bool is_min) const
{
    if (container_.size() <= 1)
        throw std::out_of_range("no span can be found.");

    int min_span = std::numeric_limits<int>::max();
    int max_span = -1;

    auto it = container_.begin();
    auto next_it = std::next(it, 1);

    while (next_it != container_.end())
    {
        // Overflow is possible when there are 2.
        const long long span = std::abs(static_cast<long long>(*next_it) - static_cast<long long>(*it));

        if (span > std::numeric_limits<int>::max())
            throw std::overflow_error("the span is overflow.");

        if (span < min_span)
            min_span = span;
        if (span > max_span)
            max_span = span;

        ++it;
        ++next_it;
    }

    return is_min ? min_span : max_span;
}

int Span::shortestSpan() const
{
    return minMaxSpan(true);
}

int Span::longestSpan() const
{
    return minMaxSpan(false);
}