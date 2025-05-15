#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 25, 5), target_(target) {};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &p) : AForm(p), target_(p.target_) {};
ShrubberyCreationForm::~ShrubberyCreationForm() {};

void ShrubberyCreationForm::operate() const
{
    std::ofstream out_file(target_ + "_shrubbery");
    if (out_file) {
        out_file << " ^ " << std::endl;
        out_file << "/|\\ " << std::endl;
        out_file << " |   " << std::endl;
        out_file.close();
    }
     
}