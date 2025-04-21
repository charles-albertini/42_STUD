/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:22 by calberti          #+#    #+#             */
/*   Updated: 2025/04/10 14:44:01 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
pour randomchump le zombie est creer et announcer dans la fonction 
donc pas besoin de new

pour new zombie on creer le zombie mais on fait l'announce en dehors
de la fonction (dans le main) donc on a besoin de new comme on
utilise un pointeur 
*/
int main()
{
    
	Zombie *horde = zombieHorde( 3, "heeeeoooo" );
	if (horde)
	{
		horde->announce();
		delete[] horde;
	}
    return 0;
	
}