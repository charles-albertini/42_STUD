#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>//pour les exceptions

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