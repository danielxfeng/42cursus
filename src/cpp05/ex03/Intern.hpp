#pragma once
#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &o);
    Intern &operator=(const Intern &o);
    ~Intern();

    AForm *makeForm(const std::string name, const std::string target);
};