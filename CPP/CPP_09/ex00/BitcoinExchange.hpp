#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdlib>


class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange& operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		//Fonctions
		void parsData(const std::string &filename);
		void parsInput(const std::string &filename);
		bool isValideDate(std::string &date);
		bool isValideValue(std::string &valueChar);
		std::string findDate(std::string &date);
		

	private:
		std::map<std::string, float> database;
};


#endif