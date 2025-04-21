/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:19:42 by calberti          #+#    #+#             */
/*   Updated: 2025/04/15 22:04:36 by calberti         ###   ########.fr       */
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

	// Opérateurs de comparaison
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Opérateurs arithmétiques
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Opérateurs d'incrémentation et décrémentation
	Fixed& operator++();    // Pré-incrémentation
	Fixed operator++(int);  // Post-incrémentation
	Fixed& operator--();    // Pré-décrémentation
	Fixed operator--(int);  // Post-décrémentation

	// Fonctions min et max statiques
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif