#pragma once
#include <string>
#include <ostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    static constexpr int MIN_GRADE = 150;
    static constexpr int MAX_GRADE = 1;
    const std::string name_;
    int grade_;
    void setGrade(int grade);
    void cannotSign(const std::string &form_name, const std::string reason);

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &o);
    Bureaucrat &operator=(const Bureaucrat &o) = delete;
    ~Bureaucrat();

    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]] int getGrade() const;
    void increaseGrade();
    void decreaseGrade();
    void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);