#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default constructor WrongAnimal called" << std::endl;
	type = "Default";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "Specifique constructor WrongAnimal called" << std::endl;
	this->type = type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "Copy constructor WrongAnimal called" << std::endl;
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Copy assignement operator WrongAnimal called" << std::endl;
	return(*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Je ne suis pas un chat" << std::endl;
}

