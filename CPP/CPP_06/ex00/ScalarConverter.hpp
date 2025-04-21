#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <limits.h>
#include <float.h>
#include <cstdlib>

class ScalarConverter
{
	private: // onmet tout les truc en priver pour pas que ca soit instanciable 
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	

	public:
	
	static void convert(std::string literal);

};



#endif