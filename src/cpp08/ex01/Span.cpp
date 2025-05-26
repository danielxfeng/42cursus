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

int Span::minMaxSpan(bool isMin) const
{
    if (container_.size() <= 1)
        throw std::out_of_range("no span can be found.");

    std::vector<int> copied_container = container_;
    std::sort(copied_container.begin(), copied_container.end());

    auto it = copied_container.begin();
    auto next_it = std::next(it, 1);

    int min_span = std::numeric_limits<int>::max();
    int max_span = -1;

    bool is_overflow = false;

    while (next_it != copied_container.end())
    {
        // Overflow is possible when there are 2 numbers like INT_MAX and INT_MIN
        const long long span = static_cast<long long>(*next_it) - static_cast<long long>(*it);

        if (span > std::numeric_limits<int>::max())
            is_overflow = true;
        if (span < min_span)
            min_span = span;
        if (span > max_span)
            max_span = span;

        ++it;
        ++next_it;
    }

    if (!isMin && is_overflow)
        throw std::overflow_error("the span is overflow.");

    return isMin ? min_span : max_span;
}

int Span::shortestSpan() const
{
    return minMaxSpan(true);
}

int Span::longestSpan() const
{
    return minMaxSpan(false);
}