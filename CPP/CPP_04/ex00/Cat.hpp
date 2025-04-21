#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	
	public:
	Cat ();
	Cat(const Cat& other);//constructeur de copie
	Cat& operator=(const Cat& other);//operateur d'affectation
	~Cat ();

	void makeSound() const;
	
};

#endif