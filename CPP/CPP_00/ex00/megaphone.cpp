#include <iostream>
#include <cctype>

char *ToUpper(char *str)
{
	int i = 0;

	if (!str)
		return(NULL);
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
	return(str);
	
}

int main (int argc, char **argv)
{
	int i = 1;
	std :: string str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return(0);
	}
	while (i < argc)
	{
		str = ToUpper(argv[i]);
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
	return(0);
}


