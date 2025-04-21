#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "MUTANT:" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "top: ";
		std::cout << mstack.top() << std::endl;
		std::cout << std::endl;

		std::cout << "size before pop: ";
		std::cout << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "size after pop: ";
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;

		mstack.push(3);
		mstack.push(2);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it; //on voit qu'on revient bien en arriere, premier truc print 5 et pas 3

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		//on construit une vrai stack a partir de notre mutant, pas de pb
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\nLIST:" << std::endl;
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "top: ";
		std::cout << mstack.back() << std::endl;
		std::cout << std::endl;

		std::cout << "size before pop: ";
		std::cout << mstack.size() << std::endl;
		mstack.pop_back();
		std::cout << "size after pop: ";
		std::cout << mstack.size() << std::endl;
		std::cout << std::endl;

		mstack.push_back(3);
		mstack.push_back(2);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it; //on voit qu'on revient bien en arriere, premier truc print 5 et pas 3

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		//on construit une vrai stack a partir de notre mutant, pas de pb
		std::list<int> s(mstack);
	}
	return 0;
}