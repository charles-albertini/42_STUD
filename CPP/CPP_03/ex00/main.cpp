/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:22 by calberti          #+#    #+#             */
/*   Updated: 2025/04/11 15:43:01 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main(void)
{
	ClapTrap bob("bob");
	bob.attack("mike");
	bob.beRepaired(5);
	bob.takeDamage(4);
	bob.beRepaired(5);
	bob.takeDamage(4);
	bob.beRepaired(5);
	bob.takeDamage(4);
	bob.takeDamage(4);
	bob.beRepaired(5);
	bob.beRepaired(5);
    return 0;
}