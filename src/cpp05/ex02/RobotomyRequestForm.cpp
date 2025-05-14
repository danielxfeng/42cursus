#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 25, 5), target_(target) {};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &p) : AForm(p), target_(p.target_) {};
RobotomyRequestForm::~RobotomyRequestForm() {};

void RobotomyRequestForm::operate() const
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    const int r = std::rand() % 2;
    std::cout << "noissssssssssssssssssssssssssssssssse. ";
    if (r == 1)
        std::cout << target_ << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}