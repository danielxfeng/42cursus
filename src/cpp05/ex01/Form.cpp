#include "Form.hpp"

Form::Form() : name_("no name"), sign_grade_(150), exec_grade_(150) {}
Form::Form(std::string name, int sign_grade, int execute_grade_) : name_(name), sign_grade_(sign_grade), exec_grade_(execute_grade_)
{
    validateGrade();
}

Form::Form(const Form &o) : name_(o.name_), sign_grade_(o.sign_grade_), exec_grade_(o.exec_grade_) { is_signed_ = o.is_signed_; }

Form::~Form() {}

const std::string &Form::getName() const { return name_; }

int Form::getSignGrade() const { return sign_grade_; }

int Form::getExecGrade() const { return exec_grade_; }

bool Form::getIsSigned() const { return is_signed_; }

void Form::validateGrade()
{
    if (exec_grade_ > MIN_GRADE || sign_grade_ > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade_ < MAX_GRADE || sign_grade_ < MAX_GRADE)
        throw GradeTooHighException();
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > sign_grade_)
        throw GradeTooLowException();
    is_signed_ = true;
}

const char *Form::GradeTooHighException::what() const noexcept
{
    return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const noexcept
{
    return "Grade Too Low";
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << obj.getName() << ", sign grade is: " << obj.getSignGrade() << ", exec grade is: " << obj.getExecGrade() << ", isSigned is: " << obj.getIsSigned() << ".";
    return os;
}