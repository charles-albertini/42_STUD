#include "ClapTrap.hpp"



ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	name = "default name";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Specifique constructor called" << std::endl;
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
    }
    return (*this);

}

void ClapTrap::attack(const std::string& target)
{
	energy_points --;
	if(energy_points < 0)
		std::cout << "ClapTrap " << name << " has 0 point of energy" << std::endl;
	if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	else if (energy_points >= 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " attack " << target << std::endl;
		std::cout<< target << " take " << attack_damage << " point of damage!"<< std::endl;
		std::cout << "ClapTrap " << name << " energy point is now " << energy_points << std::endl;
		std::cout << std::endl;
	}
	

}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points -= amount;
	if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " take " << amount << " point of damage" << std::endl;
		std::cout << "ClapTrap " << name << " hit points is now " << hit_points << std::endl;
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	energy_points--;
	if(energy_points < 0)
		std::cout << "ClapTrap " << name << " has 0 point of energy" << std::endl;
	if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
	else if (energy_points >= 0)
	{
		hit_points += amount;
		std::cout << "ClapTrap " << name << " repairs itself of " << amount << " points" << std::endl;
		std::cout << "ClapTrap " << name << " hit points is now " << hit_points << std::endl;
		std::cout << "ClapTrap " << name << " energy point is now " << energy_points << std::endl;
		std::cout << std::endl;
	}
}