#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main (void)
{
	try
	{

		Intern someRandomIntern;
		Bureaucrat man("man", 71);
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		man.signAForm(*rrf);
		std::cout << *rrf << std::endl;
		man.executeForm(*rrf);
		delete rrf;
	}

	catch (std::exception& e) 
	{
        std::cout << "Error: " << e.what() << std::endl;
    }

	
}