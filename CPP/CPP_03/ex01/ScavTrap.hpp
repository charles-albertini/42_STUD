#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

	ScavTrap();//constructeur par defaut
	ScavTrap(std::string name);//constructeur avec parametre
	~ScavTrap();//destructeur

	//fonctions
	void attack(const std::string& target);
	void guardGate();
};

#endif