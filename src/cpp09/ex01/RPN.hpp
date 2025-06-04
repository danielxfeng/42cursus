#pragma once
#include <stack>
#include <string>

typedef enum e_type
{
    NUMBER,
    OPERATOR
} t_type;

class RPN
{
private:
    std::stack<int> container_;
    int popHelper();

public:
    RPN();
    RPN(const RPN &o);
    RPN &operator=(const RPN &o);
    ~RPN();

    int calculate(std::string expr);
};