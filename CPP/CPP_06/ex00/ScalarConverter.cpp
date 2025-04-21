#include "ScalarConverter.hpp"

static void		charConvert(std::string param) 
{
	std::cout << "char: " << param[0] << std::endl;
	std::cout << "int: " << static_cast<int>(param[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(param[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(param[0]) << std::endl;
}

static void		floatConvert(std::string param) 
{
	float	n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: "  << n << "f" << std::endl; //fixed pour afficher avec un nombre fixe de decimal (definit par setprecision)
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

static void		intConvert(std::string param) 
{
	int	n = atoi(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void		doubleConvert(std::string param) 
{
	double	n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "float: " << n << std::endl;
}

static void		minInfConvert() 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}

static void		maxInfConvert() 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}

static void		nanConvert() 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf"<< std::endl;
	std::cout << "double: nan" << std::endl;
}

static void WhatInput(std::string literal)
{
	if (literal == "-inf" || literal == "-inff")
		minInfConvert();
	if (literal == "+inf" || literal == "+inff")
		maxInfConvert();
	if (literal == "nan" || literal == "nanf")
		nanConvert();

	if (literal[literal.length() - 1] == 'f' && literal.length() > 1)//float
	{
		long unsigned int i = 0;
		int point = 0;
		if(literal[i] == '-' || literal[i] == '+')
			i++;
		while (i < literal.length() - 1 && (std::isdigit(literal[i]) || literal[i] == '.'))
		{
			if (literal[i] == '.')
				point++;
			i++;
		}
		if (i == literal.length() - 1 && point <= 1)
			floatConvert(literal);
		else
			std::cout << "error: float" << std::endl;
	}

	else if (literal.find('.') != std::string::npos && literal.length() > 1)//double
	{
		long unsigned int i = 0;
		int point = 0;
		if(literal[i] == '-' || literal[i] == '+')
			i++;
		while (std::isdigit(literal[i]) || literal[i] == '.')
		{
			if (literal[i] == '.')
				point++;
			i++;
		}
		if (i == literal.length() && point <= 1)
			doubleConvert(literal);
		else
			std::cout << "error: double" << std::endl;
	}

	else if (std::isdigit(literal[0]) || (literal.length() > 1 && (literal[0] == '-' || literal[0] == '+') && std::isdigit(literal[1])))//int
	{
		long unsigned int i = 0;
		if(literal[i] == '-' || literal[i] == '+')
			i++;
		while (std::isdigit(literal[i]))
			i++;
		if (i == literal.length())
			intConvert(literal);
		else
			std::cout << "error: int" << std::endl;
	}

	else if(std::isprint(literal[0])) //char
	{
		if(literal.length() == 1)
			charConvert(literal);
		
		else 
			std::cout << "error: char" << std::endl;
	}
	else
		std::cout << "Error: convert" << std::endl;


}


void ScalarConverter::convert(std::string literal)
{
	WhatInput(literal);
}
