#include "Intern.hpp"
#include <iostream>

Intern::Intern() 
{
	std::cout << "Default constructor Intern called" << std::endl;
}

Intern::Intern(const Intern& other) 
{
    (void)other;
	std::cout << "copy constructor Intern called" << std::endl;
}

Intern::~Intern() 
{
	std::cout <<"Default destructor Intern called"<<std::endl;
}


Intern& Intern::operator=(const Intern& other) 
{
    (void)other;
	std::cout << "Copy assignement operator Intern called" << std::endl;
    return *this;
}

AForm* Intern::createShrubberyForm(const std::string& target) const 
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const 
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) const 
{
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target) const 
{
    const std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    AForm* (Intern::*formCreators[3])(const std::string&) const = {&Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};
    

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i])
		{
            AForm* form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    std::cout << "Intern cannot create form: " << formName << std::endl;
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form type not found";
}