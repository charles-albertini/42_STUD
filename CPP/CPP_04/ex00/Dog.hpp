#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	
	public:
	Dog ();
	Dog(const Dog& other);//constructeur de copie
	Dog& operator=(const Dog& other);//operateur d'affectation
	~Dog ();
	void makeSound() const;
	
};

#endif