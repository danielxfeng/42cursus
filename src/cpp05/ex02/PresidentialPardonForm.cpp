#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target_(target) {};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm(p), target_(p.target_) {};
PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::operate() const
{
    std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}