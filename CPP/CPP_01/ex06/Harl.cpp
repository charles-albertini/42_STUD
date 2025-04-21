#include "Harl.hpp"


Harl::Harl() 
{
}

Harl::~Harl() 
{
}

void Harl::debug(void) 
{
    std::cout << "DEBUG:" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) 
{
    std::cout << "INFO:" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) 
{
    std::cout << "WARNING:" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) 
{
    std::cout << "ERROR:" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) 
{
    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning,&Harl::error};
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) 
	{
        if (level == levels[i]) 
            return((this->*functions[i])());
    }
    
    std::cout << "Error: wrong level" << std::endl;
}

void Harl::filter(std::string level) {
    int levelIndex = -1;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            levelIndex = i;
            break;
        }
    }

    switch (levelIndex) 
	{
        case 0:
            this->debug();
            // pas de break donc ca va executer en cascade
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "Error: wrong level" << std::endl;
    }
}

