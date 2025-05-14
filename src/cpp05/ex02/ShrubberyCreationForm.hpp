# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target_;
        void operate() const override;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &p);
        ~ShrubberyCreationForm() override;
};