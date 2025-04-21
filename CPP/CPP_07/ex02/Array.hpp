#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array 
{
	private:

		T* arrays;
		unsigned int _size;

	public:

		Array();
		Array(unsigned int n);
		Array(const Array<T>& other);
		Array& operator=(const Array<T>& other);
		~Array();

		// Opérateur d'indexation
		T& operator[](unsigned int index);
		//meme truc mais pour const
		const T& operator[](unsigned int index) const;

		unsigned int size() const;
};


#include "Array.tpp"

#endif