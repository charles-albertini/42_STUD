#include "Fixed.hpp"

// const int Fixed::nb_bits = 8;

Fixed::Fixed()
{
	nb = 0;
	std::cout << "Default constructor called" << std::endl;
}

// Constructeur prenant un entier
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->nb = value << this->nb_bits; // Conversion en virgule fixe
}

// Constructeur prenant un float
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->nb = roundf(value * (1 << this->nb_bits)); // Conversion en virgule fixe
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->nb = other.getRawBits();
    }
    return (*this);

}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return(nb);
}

void Fixed::setRawBits(int const raw)
{
	this->nb = raw;
}
// Conversion en float
float Fixed::toFloat(void) const
{
    return (float)this->nb / (1 << this->nb_bits);
}

// Conversion en int
int Fixed::toInt(void) const
{
    return this->nb >> this->nb_bits;
}

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
