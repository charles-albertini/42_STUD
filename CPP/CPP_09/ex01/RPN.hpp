#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN 
{
	private:
		std::stack<int>	_stack;

	public:
		RPN();
		RPN(RPN const &other);
		RPN&	operator=(RPN const &other);
		~RPN();

		//Fonctions
		void addNumber(std::string tok);
		int reversePolish(std::string &calcul);
		void doCalcul(std::string tok);


};

#endif