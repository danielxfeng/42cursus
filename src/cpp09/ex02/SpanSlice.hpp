#include <span>
#include <vector>

/**
 * @brief SpanSlice maintains a slice of a span.
 * @details
 * Unlike the Span, it use an index to track the span, not the iterator.
 * It is used just because when std::rotate is applied to the base container,
 * All the sub-spans are invalid since the iterators are changed.
 */
class SpanSlice
{
private:
    std::span<int> base_;
    std::size_t idx_;
    std::size_t size_;
    void move(std::size_t offset, bool isForward);

public:
    SpanSlice() = delete;
    SpanSlice(const SpanSlice &o);
    SpanSlice &operator=(const SpanSlice &o);
    ~SpanSlice();
    SpanSlice(std::span<int> &base, std::size_t idx, std::size_t size);

    std::span<int>::iterator begin() const;
    std::span<int>::iterator end() const;
    int front() const;
    int back() const;
    std::size_t getIdx() const;

    /**
     * @brief This is to sync the indexes of SpanSlice when std::rotate is applied to base container.
     * @param container the base container
     * @param first, middle, last the indexes of base container for rotation
     */
    static void syncIndex(std::vector<SpanSlice> &container, std::size_t first, std::size_t middle, std::size_t last);
};
