#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>

class Animal
{
	protected:

	std::string type;

	public: 

	Animal();//constructeur par defaut
	Animal(std::string type);//constructeur avec parametre
	Animal(const Animal& other);//constructeur de copie
	Animal& operator=(const Animal& other);//operateur d'affectation
	virtual ~Animal();//destructeur

	//Fonctions
	virtual void makeSound() const;
	std::string getType() const;

};

#endif
