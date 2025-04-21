#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
	std::cout << "Specifique constructor Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.getName())
{
	std::cout << "copy constructor Bureaucrat called" << std::endl;
	this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignement operator Bureaucrat called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout <<"Default destructor Bureaucrat called"<<std::endl;
}

std::string Bureaucrat::getName() const
{
	return(this-> name);
}

int Bureaucrat::getGrade() const
{
	return(this-> grade);
}

void Bureaucrat::increment()
{
	if (grade > 1)
		grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
	if (grade < 150)
		grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}
void Bureaucrat::signForm(Form& form) 
{
    try 
	{
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } 
	catch (std::exception& e) 
	{
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return("A bureaucrat can't have a grade > 1");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return("A bureaucrat can't have a grade < 150");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

