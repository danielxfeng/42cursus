#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("no name"), grade_(MIN_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &o) : name_(o.name_), grade_(o.grade_) {}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::setGrade(int grade)
{
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    grade_ = grade;
}

const std::string &Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::increaseGrade() { setGrade(grade_ - 1); }

void Bureaucrat::decreaseGrade() { setGrade(grade_ + 1); }

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}
