/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:19:42 by calberti          #+#    #+#             */
/*   Updated: 2025/04/11 16:15:27 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP 

#include <iostream>
#include <string>
#include <cmath>

class ClapTrap
{
	protected:

	std::string name;
	int hit_points;
	int energy_points;
	int attack_damage;

	public:

	ClapTrap();//constructeur par defaut
	ClapTrap(std::string name);//constructeur avec parametre
	ClapTrap(const ClapTrap& other); // constructeur de copie
	ClapTrap& operator=(const ClapTrap& other);//operateur d'affectation
	~ClapTrap();//destructeur

	//fonctions
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};



#endif