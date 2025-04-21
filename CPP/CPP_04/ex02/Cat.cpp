#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Default constructor Cat called" << std::endl;
	this->brain = new Brain();
	type = "Cat";
}


Cat::~Cat()
{
	delete brain;
	std::cout << "Destructor Cat called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	std::cout << "Copy constructor Cat called" << std::endl;
	this->type = other.type;
	for (int i = 0; i < 100; i++)
	{
		this->brain[i] = other.brain[i];
	}
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		for (int i = 0; i < 100; i++)
		{
			this->brain[i] = other.brain[i];
		}
	}
	std::cout << "Copy assignement operator Cat called" << std::endl;
	return(*this);
}
void Cat::makeSound() const
{
	std::cout<< "MIAOU" << std::endl;
}