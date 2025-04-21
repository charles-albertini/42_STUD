#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), target("default") 
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), target(target) 
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) 
{
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

    checkExecutability(executor);
    
    std::cout << "DRILLING NOISES" << std::endl;
    
    std::srand(std::time(NULL));// Initialiser le générateur de nombres aléatoires, avec l'heure(comme l'heure change en permanence)
    
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy of " << target << " failed." << std::endl;
    }
}