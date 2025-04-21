/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:16:39 by calberti          #+#    #+#             */
/*   Updated: 2025/04/10 13:59:07 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//PB en c++ qund on creer un tableau d'objet avec new [] il appelle
// par defaut le constructeur sans parametre 
Zombie* zombieHorde( int N, std::string name )
{
	if (N < 0)
	{
		std::cout<<"Error: N is neg"<<std::endl;
		return(NULL);
	}
	Zombie *horde = new Zombie [N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name, i);
		std::cout << i << ": ";
		horde[i].announce();
	}
	
	return(horde);
}

