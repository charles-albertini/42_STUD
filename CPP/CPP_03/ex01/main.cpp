/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:22 by calberti          #+#    #+#             */
/*   Updated: 2025/04/11 16:38:32 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main(void)
{
	ScavTrap bob("bob");
	bob.attack("tim");
	bob.takeDamage(40);
	bob.takeDamage(40);
	bob.takeDamage(40);
	bob.guardGate();

	ClapTrap tim("tim");
	tim.attack("bob");
    return 0;
}