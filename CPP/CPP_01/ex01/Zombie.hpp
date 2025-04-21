/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:19:42 by calberti          #+#    #+#             */
/*   Updated: 2025/04/07 23:06:01 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP 

#include <iostream>
#include <string>

class Zombie
{
	private:

	std::string name;

	public:

	Zombie();
	Zombie(std::string str);
	void announce();
	void setName(std::string name, int i);

};

Zombie* zombieHorde( int N, std::string name );

#endif