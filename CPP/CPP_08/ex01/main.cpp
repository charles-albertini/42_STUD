#include "Span.hpp"

int main() {
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    {

        Span bigSpan(10000);
        
        std::vector<int> numbers;
        srand(time(NULL));
        for (int i = 0; i < 10000; ++i)
            numbers.push_back(rand() % 100000);
        
        bigSpan.addMoreNumber(numbers.begin(), numbers.end());
        
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }
    
    {
        Span sp(3);
        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(15);
        
        try 
		{
            sp.addNumber(20);
        } 
		catch (const std::exception& e) 
		{
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        Span emptySpan(5);
        try 
		{
            emptySpan.shortestSpan();
        } 
		catch (const std::exception& e) 
		{
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    
    return 0;
}


