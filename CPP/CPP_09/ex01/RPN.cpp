#include "RPN.hpp"


RPN::RPN () {}

RPN::RPN(RPN const &other) 
{
	this->_stack = other._stack;
}

RPN::~RPN() {}

RPN &	RPN::operator=(RPN const &other) 
{
	if (this != &other) 
		this->_stack = other._stack;
	return *this;
}

void RPN::addNumber(std::string tok)
{
	if(tok.size() != 1 || tok[0] < '0' || tok[0] > '9')
		throw std::logic_error("Error: Invalide number");
	int nb = tok[0] - '0';
	_stack.push(nb);
}

void RPN::doCalcul(std::string tok)
{
	if(_stack.size() < 2)
		throw std::logic_error("Error: not enough numbers");

	int b = _stack.top();
	_stack.pop();
	int a =_stack.top();
	_stack.pop();

	if (tok[0] == '/' && b == 0)
		throw std::logic_error("Error: Division by 0");

	switch (tok[0]) 
	{
		case '+':
			_stack.push(a + b);
			break;
		case '-':
			_stack.push(a - b);
			break;
		case '*':
			_stack.push(a * b);
			break;
		case '/':
			_stack.push(a / b);
		default:
			break;
	}
}

int RPN::reversePolish(std::string &calcul)
{
	std::istringstream line(calcul);
	std::string tok;
	int time = 0;

	while(line >> tok)
	{
		if(tok == "+" || tok == "-" || tok == "*" || tok == "/")
			doCalcul(tok);
		else
			addNumber(tok);
		time++;
	}

	if(_stack.size() != 1)
		throw std::logic_error("Error: Invalid expression");
	
	if (time == 1)
		throw std::logic_error("Error: Need more number");
	
	return(_stack.top());
}
