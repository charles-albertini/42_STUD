#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <algorithm>

class PmergeMe 
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        
        double _vecTime;
        double _deqTime;
        
        
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe& rhs);
        
        // truc principal
        bool parseInput(int argc, char **argv);
        void sortWithVector();
        void sortWithDeque();
        void displayResults() const;

        // vector
        void mergeInsertSortVector(std::vector<int>& vec);
        void insertSortedChainVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& result, std::vector<bool>& inserted);
        
        // deque
        void mergeInsertSortDeque(std::deque<int>& deq);
        void insertSortedChainDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& result, std::deque<bool>& inserted);
        
        //jacobsthal
        std::vector<int> getJacobsthalSequence(int n);

};

#endif


/*

1)on regroupe en paire

2) on determine le max de chaque paire

3) on trie par recursiviter les plus grand

4) inserer les petite avant leur grand des paire pur minimiser comparaison

5) tout inserer avec jacobsthal

*/