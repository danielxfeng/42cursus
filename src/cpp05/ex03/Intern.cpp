#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &o) { *this = o; }
Intern &Intern::operator=(const Intern &o)
{
    if (this != &o)
        *this = o;
    return *this;
}
Intern::~Intern() {}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
    const std::string names[] = {
        "PresidentialPardonForm",
        "RobotomyRequestForm",
        "ShrubberyCreationForm",
    };

    size_t idx = 4;
    for (size_t i = 0; i < 3; ++i)
    {
        if (names[i] == name)
        {
            idx = i;
            break;
        }
    };

    switch (idx)
    {
    case 0:
        return new PresidentialPardonForm(target);
    case 1:
        return new RobotomyRequestForm(target);
    case 2:
        return new ShrubberyCreationForm(target);
    default:
        throw std::out_of_range("Illegal form name.");
    }
}