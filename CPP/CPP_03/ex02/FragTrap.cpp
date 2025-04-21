#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default constructor FragTrap called" << std::endl;
	name = "default name";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Specifique constructor FragTrap called" << std::endl;
	this->name = name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " : Who want a high-five ?" << std::endl;
}