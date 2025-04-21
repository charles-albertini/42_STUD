/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calberti <calberti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:19:42 by calberti          #+#    #+#             */
/*   Updated: 2025/04/09 20:43:34 by calberti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP 

#include <iostream>
#include <string>

class Harl
{
	private:

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

	public:

	Harl();
	void complain(std::string level);
	void filter(std::string level);
	~Harl();

};


#endif