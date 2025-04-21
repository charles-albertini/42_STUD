#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor Brain called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor Brain called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	std::cout << "Copy assignement operator Brain called" << std::endl;
	return(*this);
}