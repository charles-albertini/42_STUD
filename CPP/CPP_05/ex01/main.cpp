#include "Bureaucrat.hpp"
#include "Form.hpp"

int main (void)
{
	//valide
	try
	{
		Form form1("test1", 25, 45);
		std::cout<< form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	//pas valide
	try
	{
		Form form2("haut", 0, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat man1("man1", 26);
		Form form1("test1", 25, 45);
		std::cout << form1 << std::endl;
		man1.signForm(form1);
		std::cout << form1 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}