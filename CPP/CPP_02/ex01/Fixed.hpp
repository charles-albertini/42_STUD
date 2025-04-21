/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:19:42 by calberti          #+#    #+#             */
/*   Updated: 2025/04/14 20:46:54 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP 

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:

	int nb;
	static const int nb_bits = 8;

	public:

	Fixed();//constructeur par defaut
	Fixed(const int value);//constructeur entier constant 
	Fixed(const float value);//constructeur flottant constant 
	Fixed(const Fixed& other); // costructeur de copie
	Fixed& operator=(const Fixed& other);//operateur d'affectation
	~Fixed();//destructeur

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;//converti en nb a virgule flottante
	int toInt(void) const;//converti en nb entier
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif