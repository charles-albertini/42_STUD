#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"
class Brain
{

	protected:

	std::string ideas[100];

	public:

	Brain();//constructeur par defaut
	Brain(const Brain& other);//constructeur de copie
	Brain& operator=(const Brain& other);//operateur d'affectation
	~Brain();//destructeur


};

#endif