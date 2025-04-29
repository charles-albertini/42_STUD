#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error: need two arguments" << std::endl;
		return(1);
	}

	BitcoinExchange btc;

	btc.parsData("data.csv");
	btc.parsInput(argv[1]);

	// std::map<std::string, float>::iterator it;
	// for (it = btc.database.begin(); it != btc.database.end(); ++it)
	// 	std::cout << it->first << "," << it->second << std::endl;  

}