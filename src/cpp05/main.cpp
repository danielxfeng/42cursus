#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    auto no_name = Bureaucrat();
    std::cout << no_name.getName() << ", " << no_name.getGrade() << std::endl;

    auto john = Bureaucrat("John", 2);
    std::cout << john << std::endl;

    auto copied_join = Bureaucrat(john);
    std::cout << copied_join << std::endl;

    john.increaseGrade();
    std::cout << john << std::endl;

    try
    {
        john.increaseGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    john.decreaseGrade();
    std::cout << john << std::endl;

    try
    {
        auto tom = Bureaucrat("Tom", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}