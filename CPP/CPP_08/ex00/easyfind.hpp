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


template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw NbNotFound();

    return it;
}





#endif