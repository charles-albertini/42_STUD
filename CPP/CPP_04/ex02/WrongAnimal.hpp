#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP


#include <iostream>
#include <string>

class WrongAnimal
{
	protected:

	std::string type;

	public: 

	WrongAnimal();//constructeur par defaut
	WrongAnimal(std::string type);//constructeur avec parametre
	WrongAnimal(const WrongAnimal& other);//constructeur de copie
	WrongAnimal& operator=(const WrongAnimal& other);//operateur d'affectation
	virtual ~WrongAnimal();//destructeur

	//Fonctions
	void makeSound() const;

};

#endif