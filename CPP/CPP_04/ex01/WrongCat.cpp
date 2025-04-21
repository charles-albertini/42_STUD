#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default constructor WrongCat called" << std::endl;
	type = "WrongCat";
}


WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "Copy constructor WrongCat called" << std::endl;
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Copy assignement operator WrongCat called" << std::endl;
	return(*this);
}
void WrongCat::makeSound() const
{
	std::cout<< "MIAOU" << std::endl;
}