/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:22 by calberti          #+#    #+#             */
/*   Updated: 2025/04/07 20:05:44 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//RAJOUTER DESTRUCTEUR !!!!!!!!!!!!!!!!!!!!!!
int main()
{
    PhoneBook phonebook;
	std::string cmd;

	while (true)
	{
		std::cout << "Please enter a command:";

		if (!getline(std::cin, cmd))
		{
			std::cout << "Error: invalid entry" << std::endl;
			break;
		}
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Command is ADD, SEARCH or EXIT. ";
	}

    return 0;
}