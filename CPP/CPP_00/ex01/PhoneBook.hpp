/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:34 by calberti          #+#    #+#             */
/*   Updated: 2025/04/02 19:43:32 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{

	private:

    Contact contacts[8];
	int currentIndex;
	int totalContacts;

    public:

	PhoneBook();
    void addContact();
	void searchContact() const;

    
};


#endif