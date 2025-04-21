#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor Dog called" << std::endl;
	type = "Dog";
}


Dog::~Dog()
{
	std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor Dog called" << std::endl;
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Copy assignement operator Dog called" << std::endl;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout<< "WOUAF" << std::endl;
}

