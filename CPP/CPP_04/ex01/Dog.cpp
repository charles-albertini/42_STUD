#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor Dog called" << std::endl;
	this->brain = new Brain();
	type = "Dog";
}


Dog::~Dog()
{
	delete brain;
	std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "Copy constructor Dog called" << std::endl;
	this->type = other.type;
	for (int i = 0; i < 100; i++)
	{
		this->brain[i] = other.brain[i];
	}
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		for (int i = 0; i < 100; i++)
		{
			this->brain[i] = other.brain[i];
		}
	}
	std::cout << "Copy assignement operator Dog called" << std::endl;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout<< "WOUAF" << std::endl;
}

