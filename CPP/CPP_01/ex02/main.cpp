/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:22 by calberti          #+#    #+#             */
/*   Updated: 2025/04/10 15:10:06 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
une reference est un alias vers une variable existante, elle ne 
peut pas etre null et ne peut pas referencer autre chose apres.
si on modifie la reference on modifie la variable */
int main()
{
	std::string brain ("HI THIS IS BRAIN");//variable
	std:: string* stringPTR = &brain;//ptr vers brain
	std::string& stringREF = brain;//reference vers brain 
	
	std::cout << &brain << std::endl;// adresse variable
	std::cout << stringPTR << std::endl;//adresse ptr
	std::cout << &stringREF << std::endl;// adresse reference 
	
	std::cout << brain << std::endl;// valeur variable
	std::cout << *stringPTR << std::endl;// valeur ptr
	std::cout << stringREF << std::endl;//valeur reference 
	
	if (&brain == stringPTR && stringPTR == &stringREF)
		std::cout << "OK, same adresse" << std::endl;
	else
		std::cout << "Error, different adresse" << std::endl;
	return 0;
	
}