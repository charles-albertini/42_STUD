/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:29 by calberti          #+#    #+#             */
/*   Updated: 2025/04/02 20:19:55 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	//ne fait rien mais tjs mettre un contructeur 	
}

void Contact::setContact() {
    std::cout << "Enter First Name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkest_secret);
}

void Contact::displaySummary(int index) const {
    std::cout << "| " << std::setw(10) << index << " | "
              << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << " | "
              << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << " | "
              << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << " |" 
              << std::endl;
}

void Contact::displayFullInfo() const {
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}