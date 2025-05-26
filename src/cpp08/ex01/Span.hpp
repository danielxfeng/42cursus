#include <vector>

class Span
{
private:
    std::vector<int> container_;
    size_t max_;

    int minMaxSpan(bool isMin) const;

public:
    Span();
    Span(unsigned int max);
    Span(const Span &o);
    Span &operator=(const Span &o);
    ~Span();

    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;
};