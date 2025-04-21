#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	AForm* createShrubberyForm(const std::string& target) const;
    AForm* createRobotomyForm(const std::string& target) const;
    AForm* createPresidentialForm(const std::string& target) const;

	public:

	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& formName, const std::string& target) const;
    
    class FormNotFoundException : public std::exception 
	{
    	public:
        virtual const char* what() const throw();
    };


};


#endif