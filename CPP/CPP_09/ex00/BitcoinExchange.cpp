#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		database = other.database;
	return(*this);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::parsData(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: can't open file" << std::endl;
		exit(1);
	}
	std::string line;
	std::getline(file, line); //on ignore la premiere ligne	

	while(std::getline(file, line))
	{
		std::istringstream newLine(line); //met line comme si c'etait un flux
		std::string date;
		std::string valueChar;
		float value;

		
		std::getline(newLine, date, ',');
		std::getline(newLine, valueChar);

		value = std::atof(valueChar.c_str());
		database[date] = value;
	}
	file.close();
}

bool BitcoinExchange::isValideDate(std::string &date)
{
	if(date.length() != 11)//check la taille
		return false;
	if (date[4] != '-' || date[7] != '-')//check les tiret
		return (false);
	if (date[10] != ' ')
		return (false);

	date.erase(date.length() - 1);//supprime l'espace

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if(!isdigit(date[i]))//check si a part les tireyt ya qu des nombre
			return(false);
	}

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)//check logique
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)//check mois de 30 jours
        return false;
    
    if (month == 2)//check annee bissextiles
	{
        bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((leapYear && day > 29) || (!leapYear && day > 28))
            return false;
    }

    return true;
	
}

bool BitcoinExchange::isValideValue(std::string &valueChar)
{
	bool dotFound = false;
	unsigned long j = 1;
	int k = valueChar.size() - 1;

	while (k >= 0 && (valueChar[k] == ' ' || valueChar[k] == '	'))
	{
    	valueChar.erase(k, 1);
    	k--;
	}
	if(valueChar[0] != ' ' || valueChar.empty())
		return(false);
	if(j < valueChar.size() && (valueChar[j] == '+' || valueChar[j] == '-'))
		j++;
    if (j >= valueChar.size())
		return false;
	for (unsigned long i = j; i < valueChar.size(); i++)
	{
        if (valueChar[i] == 'f' && i == valueChar.size() - 1)
            continue;
        if (valueChar[i] == '.')
        {
            if (dotFound || i == j)
                return false;
            dotFound = true;
        }
        else if (!isdigit(static_cast<int>(valueChar[i])))
            return false;
    }
	return(true);
}

std::string BitcoinExchange::findDate(std::string &date)
{
	std::map<std::string, float>::iterator it = database.lower_bound(date);

	if (it != database.end() && it->first == date)
        return it->first;

    if (it == database.begin() && it->first > date)
            return "";
	else
	{
		--it;
		return it->first;
	}
	
}
void BitcoinExchange::parsInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout<<"Error: can't open file"<<std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line); //saut premiere ligne

	while (std::getline(file, line))
	{
		std::istringstream newLine(line);
		std::string date;
		std::string valueChar;
		float value;

		std::getline(newLine, date, '|');
		std::getline(newLine, valueChar);

		if(!isValideDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if(!isValideValue(valueChar))
		{
			std::cout << "Error: bad input => " << valueChar << std::endl;
			continue;
		}

		value = std::atof(valueChar.c_str());

		if(value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
            std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::string dateToFind = findDate(date);
		if (dateToFind.empty())
		{
			std::cout << "Error: nothing for this date" << std::endl;
			continue;
		}

		float exchangeRate = database[dateToFind];
		float output = value * exchangeRate; 
		std::cout << date << " => " << value << " = " << output << std::endl;
	}
	file.close();

}