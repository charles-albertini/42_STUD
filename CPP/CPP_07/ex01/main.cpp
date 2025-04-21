#include "iter.hpp"


void print_size(std::string &str)
{
	std::cout << "size is: " << str.length() << std::endl;
}
void add_two(int &nb)
{
	nb +=2;
	std::cout << "new value is: " << nb << std::endl;
}
int main( void ) 
{
	std::string array1[3] = {"salut", "bonjour", "cio"};
	int array2[5] = {1, 2, 3, 4, 5};

	iter(array1, 3, print_size);
	std::cout << std::endl;
	iter(array2, 5, print_value<int>);
	std::cout << std::endl;
	iter(array2, 5, add_two);
}