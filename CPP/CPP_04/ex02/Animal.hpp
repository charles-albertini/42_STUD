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
	virtual void makeSound() const = 0;
	std::string getType() const;
	
/*
en mettant = 0 la fonction n'a plus d'implementation 
( c'est une classe abstraite), la fonction doit etre
redefini dans les classes deriver.
on ne peut pas creer d'objet de type animal
*/
};

#endif
