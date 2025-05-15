#include "Bureaucrat.hpp"
#include "Form.hpp"
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

    auto form1 = Form("Form1", 50, 99);
    std::cout << form1 << std::endl;

    auto good = Bureaucrat("good", 45);
    good.signForm(form1);

    std::cout << form1 << std::endl;

    std::cout << form1.getName() << form1.getSignGrade() << form1.getExecGrade() << form1.getIsSigned() << std::endl;

    good.signForm(form1);

    auto form2 = Form("Form2", 99, 50);
    auto bad = Bureaucrat("bad", 120);
    bad.signForm(form2);

    std::cout << form2 << std::endl;

}