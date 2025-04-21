#include "Span.hpp"

Span::Span() : maxSize(0)
{
}

Span::Span(unsigned int N) : maxSize(N)
{
	array.reserve(N);
}
Span::Span(const Span& other)
{
	this->maxSize = other.maxSize;
	this->array = other.array;
}
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->maxSize = other.maxSize;
		this->array = other.array;
	}
	return(*this);
}

Span::~Span()
{	
}

//Fonctions

void Span::addNumber(int nb)
{
	if (array.size() >= maxSize)
		throw std::length_error("Span is full");
	array.push_back(nb);
}

unsigned int Span::longestSpan()
{
	if (array.size() <= 1)
		throw std::logic_error("not enough number");

	unsigned int min = *std::min_element(array.begin(), array.end());
	unsigned int max = *std::max_element(array.begin(), array.end());

	return(max - min);
}

unsigned int Span::shortestSpan()
{
	if (array.size() <= 1)
		throw std::logic_error("not enough number");
	
	std::vector<int> sorted_array = array;
	std::sort(sorted_array.begin(), sorted_array.end());

	unsigned int tmp_min = std::numeric_limits<int>::max();
	unsigned int min = 0;

	for (unsigned int i = 1; i < sorted_array.size(); i++)
	{
		min = (sorted_array[i] - sorted_array[i - 1]);
		if (min < tmp_min)
			tmp_min = min;
	}

	return(tmp_min);
	 
}