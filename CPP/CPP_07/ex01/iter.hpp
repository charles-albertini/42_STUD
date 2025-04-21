#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename type, typename fct>
void iter(type *array, int lenght, fct(*fonction))
{
	for (int i = 0; i < lenght; i++ )
		fonction(array[i]);
}

template <typename Type>
void print_value(Type  &x)
{
    std::cout << "value is: " << x << std::endl;
}




#endif