#include "RPN.hpp"
#include "iostream"

int calHelper(char c, int a, int b)
{
    switch (c)
    {
    case ('+'):
        return a + b;
    case ('-'):
        return a - b;
    case ('*'):
        return a * b;
    case ('/'):
    {
        if (b == 0)
            throw std::invalid_argument("invalid string");
        return a / b;
    }

    default:
        throw std::runtime_error("I am a ghost.");
    }
}

t_type getType(char c)
{
    if (c >= '0' && c <= '9')
        return NUMBER;
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return OPERATOR;
    throw std::invalid_argument("invalid string");
}

RPN::RPN() {}
RPN::RPN(const RPN &o) : container_(o.container_) {};
RPN &RPN::operator=(const RPN &o)
{
    if (this == &o)
        return *this;
    container_ = o.container_;
    return *this;
}
RPN::~RPN() {}

int RPN::popHelper()
{
    if (container_.empty())
        throw std::invalid_argument("invalid string");
    const int a = container_.top();
    container_.pop();
    return a;
}

int RPN::calculate(std::string expr)
{
    for (size_t i = 0; i < expr.length(); ++i)
    {
        // The expression is "1 2 +", so we skip the even indexed char.
        if (i % 2 == 1)
        {
            if (expr[i] != ' ')
                throw std::invalid_argument("invalid string");
            continue;
        }

        char c = expr[i];
        const t_type type = getType(c);

        switch (type)
        {
        case NUMBER:
        {
            container_.push(static_cast<int>(c - '0'));
            break;
        };
        case OPERATOR:
        {
            int right = popHelper();
            int left = popHelper();

            container_.push(calHelper(c, left, right));
            break;
        }
        default:
            throw std::runtime_error("I am a ghost.");
        }
    }

    int result = popHelper();
    if (!container_.empty()) // The stack should be empty after the calculation.
        throw std::invalid_argument("invalid string");

    return result;
}