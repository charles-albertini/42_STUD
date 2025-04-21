/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:22 by calberti          #+#    #+#             */
/*   Updated: 2025/04/11 22:05:15 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


int main(void)
{
	FragTrap bob("bob");
	bob.attack("tim");
	bob.takeDamage(40);
	bob.takeDamage(40);
	bob.takeDamage(40);
	bob.highFivesGuys();

	ClapTrap tim("tim");
	tim.attack("bob");
    return 0;
}