#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

	std::string const name;
	bool signe;
	int const signGrade;
	int const executeGrade;

	public:

	AForm();
	AForm(std::string const name, int const signGrade, int const executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	//Fonctions
	std::string getName()const;
	bool isSigned() const;
	int getGradeToSign()const;
	int getGradeToExecute()const;

	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	void checkExecutability(Bureaucrat const & executor) const;

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
	class FormNotSignedException : public std::exception 
	{
    	public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif