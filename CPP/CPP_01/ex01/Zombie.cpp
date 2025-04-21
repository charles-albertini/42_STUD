/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:04:23 by calberti          #+#    #+#             */
/*   Updated: 2025/04/10 14:46:21 by calberti         ###   ########.fr       */
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

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string str, int i)
{
	if (i == 0)
		name = str+"[premier]";
    else
		name = str;
}