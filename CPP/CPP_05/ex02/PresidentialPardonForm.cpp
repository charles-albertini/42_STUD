#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Request Form", 25, 5), target("default") 
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Request Form", 25, 5), target(target) 
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) 
{
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) 
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

    checkExecutability(executor);
    
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}