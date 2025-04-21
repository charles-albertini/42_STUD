#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:

	Brain* brain;

	public:
	Cat ();
	Cat(const Cat& other);//constructeur de copie
	Cat& operator=(const Cat& other);//operateur d'affectation
	~Cat ();

	void makeSound() const;
	
	
};

#endif