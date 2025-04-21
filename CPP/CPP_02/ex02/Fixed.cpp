#include "Fixed.hpp"

const int Fixed::nb_bits = 8;

Fixed::Fixed()
{
	nb = 0;
	// std::cout << "Default constructor called" << std::endl;
}

// Constructeur prenant un entier
Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    this->nb = value << this->nb_bits; // Conversion en virgule fixe
}
/*
<< decale vers la gauche (on fait x 2^nb_bits): 
5 << 8 = 5 x 256 = 1280 
et 1280 c'est 5.0 en virgule fixe
*/

// Constructeur prenant un float
Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->nb = roundf(value * (1 << this->nb_bits)); // Conversion en virgule fixe
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->nb = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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
    return (float)this->nb / (1 << this->nb_bits); // on fait l'inverse du constructeur float
}

// Conversion en int
int Fixed::toInt(void) const
{
    return this->nb >> this->nb_bits; 
}
/*
fait l'inverse du constructeur int 
>> faiot une division entiere donc on recupere juste la partie entiere 
*/ 

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
/*
permet d'afficher un fixed comme un float
*/

// Opérateurs de comparaison
bool Fixed::operator>(const Fixed& other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->getRawBits() != other.getRawBits();
}

// Opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    // Multiplication en virgule fixe nécessite un ajustement pour éviter l'overflow
    long long temp = (long long)this->getRawBits() * (long long)other.getRawBits();
    result.setRawBits((int)(temp >> this->nb_bits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    // Vérification de division par zéro
    if (other.getRawBits() == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        exit(1);
    }
    
    Fixed result;
    // Division en virgule fixe nécessite un ajustement
    long long temp = ((long long)this->getRawBits() << this->nb_bits) / other.getRawBits();
    result.setRawBits((int)temp);
    return result;
}

// Opérateurs d'incrémentation et décrémentation
Fixed& Fixed::operator++() // Pré-incrémentation
{
    this->nb++;
    return *this;
}

Fixed Fixed::operator++(int) // Post-incrémentation
{
    Fixed temp(*this);
    this->nb++;
    return temp;
}

Fixed& Fixed::operator--() // Pré-décrémentation
{
    this->nb--;
    return *this;
}

Fixed Fixed::operator--(int) // Post-décrémentation
{
    Fixed temp(*this);
    this->nb--;
    return temp;
}

// Fonctions min et max statiques
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}
