#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    static constexpr int MIN_GRADE = 150;
    static constexpr int MAX_GRADE = 1;
    const std::string name_;
    const int sign_grade_;
    const int exec_grade_;
    bool is_signed_{false};
    void validateGrade();
    virtual void operate() const = 0;

public:
    AForm();
    AForm(std::string name, int sign_grade, int execute_grade_);
    AForm(const AForm &o);
    AForm &operator=(const AForm &o) = delete;
    virtual ~AForm();

    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]] int getSignGrade() const;
    [[nodiscard]] int getExecGrade() const;
    [[nodiscard]] bool getIsSigned() const;
    void beSigned(const Bureaucrat &b);

    void execute(Bureaucrat const & executor) const;



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

    class NotSignException : public std::exception
    {
    public:
        virtual const char *what() const noexcept override;
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);