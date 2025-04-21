#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <stdexcept>

class NbNotFound : public std::exception
{
	public:
	virtual const char * what() const throw()
	{
		return "No occurence found";
	}
};


template <typename type>
int easyfind(type &array, int nb)
{
	typename type:: iterator it;

	for (it = array.begin(); it != array.end(); it ++)
		if (*it == nb)
			return(*it);
	throw NbNotFound();
}





#endif