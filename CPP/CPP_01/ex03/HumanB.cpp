/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:16:39 by calberti          #+#    #+#             */
/*   Updated: 2025/04/09 21:55:39 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	weapon = NULL;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this ->weapon = &weapon;
}
void HumanB::attack()
{
	if (weapon == NULL)
		std::cout << this->name << " attacks with " << "no weapon" << std::endl; // le cas ou y a pas set weapon 
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	
}

