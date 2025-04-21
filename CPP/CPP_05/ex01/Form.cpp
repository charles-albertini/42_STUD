#include "Form.hpp"

Form::Form() : name("Default"), signe(false), signGrade(150), executeGrade(150)
{
	std::cout << "Default constructor Form called" << std::endl;
}

Form::Form(const std::string name, int signGrade, int executeGrade) : name(name), signe(false), signGrade(signGrade), executeGrade(executeGrade) 
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
    std::cout << "Specifique constructor Form called" << std::endl;
}

Form::Form(const Form& other): name(other.name), signe(other.signe), signGrade(other.signGrade), executeGrade((other.executeGrade))
{
	std::cout << "copy constructor Form called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Copy assignement operator Form called" << std::endl;
	if (this != &other)
		signe = other.signe; //les autre sont des const on peut pas y toucher
	return(*this);
}

Form::~Form()
{
	std::cout <<"Default destructor Form called"<<std::endl;
}

//FONCTIONS

std::string Form::getName() const
{
	return name;
}

bool Form::isSigned() const
{
	return signe;
}

int Form::getGradeToExecute()const
{
	return executeGrade;
}

int Form::getGradeToSign()const
{
	return signGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() <= signGrade)
        signe = true;
    else
        throw Form::GradeTooLowException();
}

//Class exception

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this form");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade too low for this form");
}

//Surcharge

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	 os << "Form: " << form.getName() << std::endl
       << "Sign Status: " << (form.isSigned() ? "Signed" : "Not signed") << std::endl
       << "Grade to Sign: " << form.getGradeToSign() << std::endl
       << "Grade to Execute: " << form.getGradeToExecute();
    return os;
}