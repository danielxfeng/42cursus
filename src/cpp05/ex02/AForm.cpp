#include "AForm.hpp"

AForm::AForm() : name_("no name"), sign_grade_(150), exec_grade_(150) {}
AForm::AForm(std::string name, int sign_grade, int execute_grade_) : name_(name), sign_grade_(sign_grade), exec_grade_(execute_grade_)
{
    validateGrade();
}

AForm::AForm(const AForm &o) : name_(o.name_), sign_grade_(o.sign_grade_), exec_grade_(o.exec_grade_) { is_signed_ = o.is_signed_; }

AForm::~AForm() {}

const std::string &AForm::getName() const { return name_; }

int AForm::getSignGrade() const { return sign_grade_; }

int AForm::getExecGrade() const { return exec_grade_; }

bool AForm::getIsSigned() const { return is_signed_; }

void AForm::validateGrade()
{
    if (exec_grade_ > MIN_GRADE || sign_grade_ > MIN_GRADE)
        throw GradeTooLowException();
    if (exec_grade_ < MAX_GRADE || sign_grade_ < MAX_GRADE)
        throw GradeTooHighException();
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > sign_grade_)
        throw GradeTooLowException();
    is_signed_ = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!is_signed_)
        throw NotSignException();
    if (executor.getGrade() > exec_grade_)
        throw GradeTooLowException();
    operate();
}

const char *AForm::GradeTooHighException::what() const noexcept
{
    return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
    return "Grade Too Low";
}

const char *AForm::NotSignException::what() const noexcept
{
    return "The Form Has Not Been Signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << obj.getName() << ", sign grade is: " << obj.getSignGrade() << ", exec grade is: " << obj.getExecGrade() << ", isSigned is: " << obj.getIsSigned() << ".";
    return os;
}