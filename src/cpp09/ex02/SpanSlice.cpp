#include "SpanSlice.hpp"
#include <iostream>

SpanSlice::SpanSlice(std::span<int> &base, std::size_t idx, std::size_t size) : base_(base), idx_(idx), size_(size) {}

SpanSlice::SpanSlice(const SpanSlice &o) : base_(o.base_), idx_(o.idx_), size_(o.size_) {}

SpanSlice &SpanSlice::operator=(const SpanSlice &o)
{
    if (this != &o)
    {
        base_ = o.base_;
        idx_ = o.idx_;
        size_ = o.size_;
    }
    return *this;
}

SpanSlice::~SpanSlice() {}

std::span<int>::iterator SpanSlice::begin() const { return base_.begin() + idx_; }

std::span<int>::iterator SpanSlice::end() const { return base_.begin() + idx_ + size_; }

int SpanSlice::front() const { return *(begin()); }

int SpanSlice::back() const { return *(end() - 1); }

void SpanSlice::move(std::size_t distance, bool isForward) { idx_ += distance * (isForward ? 1 : -1); }

std::size_t SpanSlice::getIdx() const { return idx_; }

void SpanSlice::syncIndex(std::vector<SpanSlice> &container, std::size_t first, std::size_t middle, std::size_t last)
{
    const std::size_t right_offset = last - middle;
    const std::size_t left_offset = middle - first;
    for (SpanSlice &curr : container)
    {
        if (curr.getIdx() < first || curr.getIdx() >= last)
            continue;
        if (curr.getIdx() < middle)
        {
            std::cout << "syncIndex -> right: " << curr.back() << ", " << right_offset << std::endl;
            curr.move(right_offset, true);
        }
            
        else
        {
            std::cout << "syncIndex left <- : " << curr.back() << ", " << left_offset << std::endl;
            curr.move(left_offset, false);
        }
            
    }
}