#include "SpanSlice.hpp"

SpanSlice::~SpanSlice() {}

SpanSlice::SpanSlice(std::span<int> &base, std::size_t idx, std::size_t size) : base_(base), idx_(idx), size_(size) {}

std::span<int>::iterator SpanSlice::begin() const { return base_.begin() + idx_; }

std::span<int>::iterator SpanSlice::end() const { return base_.begin() + idx_ + size_; }

int SpanSlice::front() const { return *(begin()); }

int SpanSlice::back() const { return *(end() - 1); }

void SpanSlice::move(std::size_t distance, bool isForward) { idx_ += distance * (isForward ? 1 : -1); }

static void SpanSlice::rotate(std::vector<SpanSlice> &container, std::size_t first, std::size_t middle, std::size_t last)
{
    const std::size_t right_offset = last - middle;
    const std::size_t left_offset = middle - first;
    for (std::size_t i = first; i < last; ++i)
    {
        if (i < middle)
            container[i].move(right_offset, true);
        else
            container[i].move(left_offset, false);
    }
}