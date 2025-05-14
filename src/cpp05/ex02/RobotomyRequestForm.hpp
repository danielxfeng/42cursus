# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target_;
        void operate() const override;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &p);
        ~RobotomyRequestForm() override;
};