#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	type = "Default";
}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria specifique constructor called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "Copy constructor AMateria called" << std::endl;
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "Copy assignement operator AMateria called" << std::endl;
	if(this != &other)
		this->type = other.type;
	return(*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria called" << std::endl;
}

std::string const& AMateria:: getType() const
{
	return(this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "AMateria base use function" << std::endl;
}

