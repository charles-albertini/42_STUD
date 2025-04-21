/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:19:42 by calberti          #+#    #+#             */
/*   Updated: 2025/04/09 19:53:27 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP 

#include <iostream>
#include <string>

class Weapon
{
	private:

	std::string type;

	public:

	Weapon(std::string weapon);
	const std::string &getType() const;
	void setType(std::string new_type);
	~Weapon();

};


#endif