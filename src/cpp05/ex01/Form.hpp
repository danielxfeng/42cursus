#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    static constexpr int MIN_GRADE = 150;
    static constexpr int MAX_GRADE = 1;
    const std::string name_;
    const int sign_grade_;
    const int exec_grade_;
    bool is_signed_{false};
    void validateGrade();

public:
    Form();
    Form(std::string name, int sign_grade, int execute_grade_);
    Form(const Form &o);
    Form &operator=(const Form &o) = delete;
    ~Form();

    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]] int getSignGrade() const;
    [[nodiscard]] int getExecGrade() const;
    [[nodiscard]] bool getIsSigned() const;
    void beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const noexcept override;
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const noexcept override;
    };
};

std::ostream &operator<<(std::ostream &os, const Form &obj);