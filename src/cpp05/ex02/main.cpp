#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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

    auto pdf = PresidentialPardonForm("pdf");
    std::cout << pdf << std::endl;

    auto p1 = Bureaucrat("p1", pdf.getExecGrade() - 1);
    p1.executeForm(pdf);

    auto p3 = Bureaucrat("p3", pdf.getSignGrade() - 1);
    p3.signForm(pdf);

    auto p2 = Bureaucrat("p2", pdf.getExecGrade() + 1);
    p2.executeForm(pdf);

    auto p4 = Bureaucrat("p4", pdf.getExecGrade() - 1);
    p4.executeForm(pdf);

    auto rrf = RobotomyRequestForm("rrf");

    auto r1 = Bureaucrat("r1", rrf.getExecGrade() - 1);
    r1.executeForm(rrf);

    auto r3 = Bureaucrat("r3", rrf.getSignGrade() - 1);
    r3.signForm(rrf);

    auto r2 = Bureaucrat("r2", rrf.getExecGrade() + 1);
    r2.executeForm(rrf);

    auto r4 = Bureaucrat("r4", rrf.getExecGrade() - 1);
    r4.executeForm(rrf);

    auto scf = ShrubberyCreationForm("scf");

    auto s1 = Bureaucrat("s1", scf.getExecGrade() - 1);
    s1.executeForm(scf);

    auto s3 = Bureaucrat("s3", scf.getSignGrade() - 1);
    s3.signForm(scf);

    auto s2 = Bureaucrat("s2", scf.getExecGrade() + 1);
    s2.executeForm(scf);

    auto s4 = Bureaucrat("s4", scf.getExecGrade() - 1);
    s4.executeForm(scf);
}