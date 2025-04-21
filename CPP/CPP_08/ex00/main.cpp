#include "easyfind.hpp"



int main()
{
    std::vector<int> array1;
	std::list<int> array2;
	
	int find;

	array1.push_back(1);
	array1.push_back(8);
	array1.push_back(2);

	try
	{
		find = easyfind(array1, 8);
		std::cout << find << std::endl;
	}
	catch (const std::exception& e) 
	{
        std::cout << e.what() << std::endl;
    }

	array2.push_back(4);
	array2.push_back(9);
	array2.push_back(1);

	try
	{
		find = easyfind(array2, 1);
		std::cout << find << std::endl;
	}
	catch (const std::exception& e) 
	{
        std::cout << e.what() << std::endl;
    }


}

