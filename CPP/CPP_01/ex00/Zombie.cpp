/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:04:23 by calberti          #+#    #+#             */
/*   Updated: 2025/04/07 22:34:30 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Default")
{
	// set le name a defualt 
}

Zombie::Zombie(std::string str) : name(str)
{
	// set le name a str
}
Zombie::~Zombie()
{
	std::cout << name << " : is dead" << std::endl;
}
void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}