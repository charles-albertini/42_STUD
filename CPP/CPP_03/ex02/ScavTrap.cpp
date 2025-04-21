#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default constructor ScavTrap called" << std::endl;
	name = "default name";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Specifique constructor ScavTrap called" << std::endl;
	this->name = name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	energy_points --;
	if(energy_points < 0)
		std::cout << "ScavTrap " << name << " has 0 point of energy" << std::endl;
	if (hit_points <= 0)
		std::cout << "ScavTrap " << name << " is dead" << std::endl;
	else if (energy_points >= 0 && hit_points > 0)
	{
		std::cout << "ScavTrap " << name << " attack " << target << std::endl;
		std::cout<< target << " take " << attack_damage << " point of damage!"<< std::endl;
		std::cout << "ScavTrap " << name << " energy point is now " << energy_points << std::endl;
		std::cout << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (hit_points <= 0)
		std::cout << name << " is dead" << std::endl;
	else
		std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}