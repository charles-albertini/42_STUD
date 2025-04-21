#ifndef WRONGWrongCat_HPP
#define WRONGWrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	
	public:
	WrongCat ();
	WrongCat(const WrongCat& other);//constructeur de copie
	WrongCat& operator=(const WrongCat& other);//operateur d'affectation
	~WrongCat ();

	void makeSound() const;
	
};

#endif