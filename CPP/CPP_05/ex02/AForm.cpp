#include "AForm.hpp"

AForm::AForm() : name("Default"), signe(false), signGrade(150), executeGrade(150)
{
	std::cout << "Default constructor AForm called" << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int executeGrade) : name(name), signe(false), signGrade(signGrade), executeGrade(executeGrade) 
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
    std::cout << "Specifique constructor AForm called" << std::endl;
}

AForm::AForm(const AForm& other): name(other.name), signe(other.signe), signGrade(other.signGrade), executeGrade((other.executeGrade))
{
	std::cout << "copy constructor AForm called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "Copy assignement operator AForm called" << std::endl;
	if (this != &other)
		signe = other.signe; //les autre sont des const on peut pas y toucher
	return(*this);
}

AForm::~AForm()
{
	std::cout <<"Default destructor AForm called"<<std::endl;
}

//FONCTIONS

std::string AForm::getName() const
{
	return name;
}

bool AForm::isSigned() const
{
	return signe;
}

int AForm::getGradeToExecute()const
{
	return executeGrade;
}

int AForm::getGradeToSign()const
{
	return signGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) 
{
    if (bureaucrat.getGrade() <= signGrade)
        signe = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::checkExecutability(const Bureaucrat& executor) const 
{
    if (!signe)
        throw FormNotSignedException();
    if (executor.getGrade() > executeGrade)
        throw GradeTooLowException();
}

//Class exception

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this AForm");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low for this AForm");
}

const char* AForm::FormNotSignedException::what() const throw() 
{
    return "Form is not signed";
}

//Surcharge

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	 os << "AForm: " << AForm.getName() << std::endl
       << "Sign Status: " << (AForm.isSigned() ? "Signed" : "Not signed") << std::endl
       << "Grade to Sign: " << AForm.getGradeToSign() << std::endl
       << "Grade to Execute: " << AForm.getGradeToExecute();
    return os;
}