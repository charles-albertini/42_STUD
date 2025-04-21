#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	if (weapon.empty())
		type = "default weapon";
	else
		type = weapon;
}
const std::string  &Weapon::getType() const
{
	return (this->type);
}

void Weapon::setType(std::string new_type)
{
	if(new_type.empty())
		type = "default weapon";
	else
		type = new_type;
}
Weapon::~Weapon()
{

}