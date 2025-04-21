#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>



class Span
{
	private:
		unsigned int maxSize;
		std::vector<int> array;


	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		//Fonctions
		void addNumber(int nb);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		template<typename type>
		void addMoreNumber(type begin, type end);

};

template<typename type>
void Span::addMoreNumber(type begin, type end)
{
	if (static_cast<unsigned long>(std::distance(begin, end)) > maxSize - array.size())
		throw std::length_error("Too low capacity");
	array.insert(array.end(), begin, end);
}



#endif