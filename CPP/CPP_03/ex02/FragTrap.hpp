#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

	FragTrap();//constructeur par defaut
	FragTrap(std::string name);//constructeur avec parametre
	~FragTrap();//destructeur

	//fonctions
	void highFivesGuys(void);
};

#endif