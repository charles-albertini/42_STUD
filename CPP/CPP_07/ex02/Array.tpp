#ifndef ARRAY_TPP
#define ARRAY_TPP

#include"Array.hpp"

template <typename T>
Array<T>::Array() : arrays(NULL), _size(0) 
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) 
{
    arrays = new T[n]();
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size) 
{
    arrays = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        arrays[i] = other.arrays[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) 
{
    if (this != &other) 
	{
        delete[] arrays;
        _size = other._size;
        arrays = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            arrays[i] = other.arrays[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] arrays;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index hors limites");
    return arrays[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const 
{
    if (index >= _size)
        throw std::out_of_range("Index hors limite");
    return arrays[index];
}

template <typename T>
unsigned int Array<T>::size() const 
{
    return _size;
}

#endif