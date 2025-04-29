#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe merger;
    
    if (!merger.parseInput(argc, argv)) {
        std::cerr << "Error: wrong argument" << std::endl;
        return 1;
    }
    
    merger.sortWithVector();
    merger.sortWithDeque();

    merger.displayResults();

    return 0;
}