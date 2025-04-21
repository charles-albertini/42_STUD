#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor Animal called" << std::endl;
	type = "Default";
}

Animal::Animal(std::string type)
{
	std::cout << "Specifique constructor Animal called" << std::endl;
	this->type = type;
}

Animal::~Animal()
{
	std::cout << "Destructor Animal called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy constructor Animal called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Copy assignement operator Animal called" << std::endl;
	return(*this);
}

void Animal::makeSound() const
{
	std::cout << "Je suis un animal" << std::endl;
}

std::string Animal::getType() const
{
	return(type);
}
