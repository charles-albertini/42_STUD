#include "Bureaucrat.hpp"

int main (void)
{

	try
	{
		Bureaucrat bureaucrat("charly", 500);
		while(1)
		{
			bureaucrat.increment();
			std::cout << bureaucrat << std::endl;
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("charly_2", 5);
		while(1)
		{
			bureaucrat.increment();
			std::cout << bureaucrat << std::endl;
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat bureaucrat("charly_3", 145);
		while(1)
		{
			bureaucrat.decrement();
			std::cout << bureaucrat << std::endl;
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}