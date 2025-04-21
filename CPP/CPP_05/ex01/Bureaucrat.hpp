#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>//pour les exceptions
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:

	std::string const name;
	int grade;

	public:

	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	//Fonctions
	std::string getName()const;
	int getGrade()const;
	void increment();
	void decrement();
	void signForm(Form& form);

	class GradeTooHighException : public std::exception 
	{
		public:
		const char * what() const throw();
	};
	class GradeTooLowException : public std::exception 
	{
		public:
		const char * what() const throw();
	};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif