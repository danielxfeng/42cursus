#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &o) { *this = o; }
Intern &Intern::operator=(const Intern &o)
{
    if (this != &o)
    {
    }
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

    typedef AForm *(*FormFactory)(const std::string &);

    FormFactory factory[] = {
        [](const std::string &t) -> AForm *
        { return new PresidentialPardonForm(t); },
        [](const std::string &t) -> AForm *
        { return new RobotomyRequestForm(t); },
        [](const std::string &t) -> AForm *
        { return new ShrubberyCreationForm(t); },
    };

    for (size_t i = 0; i < 3; ++i)
    {
        if (names[i] == name)
        {
            return factory[i](target);
        }
    }
    throw std::out_of_range("Illegal form name.");
}