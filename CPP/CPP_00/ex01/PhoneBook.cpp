/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:36 by calberti          #+#    #+#             */
/*   Updated: 2025/04/07 20:08:37 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
	currentIndex = 0;
	totalContacts = 0;
}

void PhoneBook::addContact() {
    std::cout << "Adding a new contact..." << std::endl;
    contacts[currentIndex].setContact();

    currentIndex = (currentIndex + 1) % 8;

    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::searchContact() const {
    if (totalContacts == 0) {
        std::cout << "No contacts found" << std::endl;
        return;
    }

    std::cout << "|     Index | First Name |  Last Name |  Nickname  |" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

    for (int i = 0; i < totalContacts; i++) {
        contacts[i].displaySummary(i + 1);
    }

    std::cout << "Enter contact index: ";
    std::string input;
	if (!getline(std::cin, input))
	{
		std::cout << "Error: invalid entry" << std::endl;
		exit (0);
	}

    int index = 0;
	std::istringstream(input) >> index;
	
    while (index < 1 || index > totalContacts)
	{
    	std::cout << "Index is between 1 and " << totalContacts << std::endl;
		std::cout << "Enter contact index: ";
    	std::string input;
    	std::getline(std::cin, input);

    	std::istringstream(input) >> index;
    }
    contacts[index - 1].displayFullInfo();
}