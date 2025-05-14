# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string target_;
        void operate() const override;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &p);
        ~PresidentialPardonForm() override;
};