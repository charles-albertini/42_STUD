#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor Cat called" << std::endl;
	type = "Cat";
}


Cat::~Cat()
{
	std::cout << "Destructor Cat called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor Cat called" << std::endl;
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Copy assignement operator Cat called" << std::endl;
	return(*this);
}
void Cat::makeSound() const
{
	std::cout<< "MIAOU" << std::endl;
}