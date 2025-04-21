/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:19:42 by calberti          #+#    #+#             */
/*   Updated: 2025/04/15 22:03:55 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP 

#include <iostream>
#include <string>

class Fixed
{
	private:

	int nb;
	static const int nb_bits;

	public:

	Fixed();
	Fixed(const Fixed& other); // costructeur de copie
	Fixed& operator=(const Fixed& other);//operateur d'affectation
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

};


#endif