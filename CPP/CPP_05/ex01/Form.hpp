#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

	std::string const name;
	bool signe;
	int const signGrade;
	int const executeGrade;

	public:

	Form();
	Form(std::string const name, int const signGrade, int const executeGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	//Fonctions
	std::string getName()const;
	bool isSigned() const;
	int getGradeToSign()const;
	int getGradeToExecute()const;
	void beSigned(const Bureaucrat& bureaucrat);

	//class d'exception
	class GradeTooHighException : public std::exception 
	{
    	public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception 
	{
    	public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif