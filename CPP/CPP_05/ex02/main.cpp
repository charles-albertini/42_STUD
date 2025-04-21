#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main (void)
{
	try
	{

		Bureaucrat man("man", 1);
		std::cout << man << std::endl;
		std::cout << std::endl;
		ShrubberyCreationForm shrubbery("Garden");
		std::cout << shrubbery << std::endl;
		std::cout << std::endl;
		man.executeForm(shrubbery);
		std::cout << std::endl;
		man.signAForm(shrubbery);
		std::cout << std::endl;
		man.executeForm(shrubbery);
		std::cout << std::endl;


		Bureaucrat man2("man2", 1);
		std::cout << man2 << std::endl;
		std::cout << std::endl;
		RobotomyRequestForm robot("robot");
		std::cout << robot << std::endl;
		man2.signAForm(robot);
		std::cout << std::endl;
		man2.executeForm(robot);
		std::cout << std::endl;

		Bureaucrat man3("man3", 1);
		std::cout << man3 << std::endl;
		std::cout << std::endl;
		PresidentialPardonForm presidential("presidential");
		std::cout << presidential << std::endl;
		man3.signAForm(presidential);
		std::cout << std::endl;
		man3.executeForm(presidential);
		std::cout << std::endl;
	}

	catch (std::exception& e) 
	{
        std::cout << "Exception non gérée: " << e.what() << std::endl;
    }

	
}