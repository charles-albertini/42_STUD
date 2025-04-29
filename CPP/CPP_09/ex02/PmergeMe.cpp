#include "PmergeMe.hpp"


PmergeMe::PmergeMe() : _vecTime(0), _deqTime(0) {}

PmergeMe::PmergeMe(const PmergeMe& src) 
{
    *this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
    if (this != &rhs) 
    {
        _vec = rhs._vec;
        _deq = rhs._deq;
        _vecTime = rhs._vecTime;
        _deqTime = rhs._deqTime;
    }
    return *this;
}

// parsing
bool PmergeMe::parseInput(int argc, char **argv) 
{
    if (argc <= 1)
        return false;

    for (int i = 1; i < argc; ++i) 
    {
        std::string arg = argv[i];
        std::istringstream iss(arg);
        int num;
        
        if (!(iss >> num) || num < 0 || iss.peek() != EOF)
            return false;
        
        _vec.push_back(num);
        _deq.push_back(num);
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
    return true;
}

// vector
void PmergeMe::sortWithVector() 
{
    clock_t start = clock();
    mergeInsertSortVector(_vec);
    clock_t end = clock();
    _vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) 
{
    if (vec.size() <= 1)
        return;

    // 1) et 2) paires
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = false;
    int oddElement = 0;

    for (size_t i = 0; i < vec.size(); i += 2) 
    {
        if (i + 1 < vec.size()) 
        {
            int first = vec[i];
            int second = vec[i + 1];
            if (first < second)
                pairs.push_back(std::make_pair(second, first));
            else
                pairs.push_back(std::make_pair(first, second));
        } 
        else 
        {
            hasOdd = true;
            oddElement = vec[i];
        }
    }

    // 3) Trie recursif des plus grands
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    mergeInsertSortVector(mainChain);


    // 4) on remet les petit avant leur grands des paire dans les grands trier 
	int minElement = *std::min_element(mainChain.begin(), mainChain.end());

    int associatedSmall = 0;
    size_t indexOfMinPair = 0;
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (pairs[i].first == minElement) 
        {
            associatedSmall = pairs[i].second;
            indexOfMinPair = i;
            break;
        }
    }

    std::vector<int>::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it != minElement)
        ++it;
    mainChain.insert(it, associatedSmall);

    std::vector<bool> inserted(pairs.size(), false);
    inserted[indexOfMinPair] = true;

	// 5) jacobsthal
    insertSortedChainVector(pairs, mainChain, inserted);

    if (hasOdd) 
    {
        std::vector<int>::iterator it = mainChain.begin();
        while (it != mainChain.end() && *it < oddElement)
            ++it;
        mainChain.insert(it, oddElement);
    }
    vec = mainChain;
}

void PmergeMe::insertSortedChainVector(std::vector<std::pair<int, int> >& pairs, std::vector<int>& result, std::vector<bool>& inserted)
{

    std::vector<int> jacobsthalSequence = getJacobsthalSequence(pairs.size());

    for (size_t i = 0; i < jacobsthalSequence.size(); ++i) 
    {
        int idx = jacobsthalSequence[i];
        if (idx < static_cast<int>(pairs.size()) && !inserted[idx]) 
        {
            std::vector<int>::iterator it = result.begin();
            while (it != result.end() && *it < pairs[idx].second)
                ++it;
            result.insert(it, pairs[idx].second);
            inserted[idx] = true;
        }
    }
	for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (!inserted[i]) 
        {
            std::vector<int>::iterator it = result.begin();
            while (it != result.end() && *it < pairs[i].second)
                ++it;
            result.insert(it, pairs[i].second);
        }
    }
}



// deque
void PmergeMe::sortWithDeque() 
{
    clock_t start = clock();
    mergeInsertSortDeque(_deq);
    clock_t end = clock();
    _deqTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq) 
{
    if (deq.size() <= 1)
        return;

    // 1) et 2) pair
    std::deque<std::pair<int, int> > pairs;
    bool hasOdd = false;
    int oddElement = 0;

    for (size_t i = 0; i < deq.size(); i += 2) 
    {
        if (i + 1 < deq.size()) 
        {
            int first = deq[i];
            int second = deq[i + 1];
            if (first < second)
                pairs.push_back(std::make_pair(second, first));
            else
                pairs.push_back(std::make_pair(first, second));
        } 
        else 
        {
            hasOdd = true;
            oddElement = deq[i];
        }
    }

    // 3) trie recursif des plus grand 
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    mergeInsertSortDeque(mainChain);

    // 4) on remet les plus pett avant les plus grand
	int minElement = *std::min_element(mainChain.begin(), mainChain.end());

    int associatedSmall = 0;
    size_t indexOfMinPair = 0;
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (pairs[i].first == minElement) 
        {
            associatedSmall = pairs[i].second;
            indexOfMinPair = i;
            break;
        }
    }

    std::deque<int>::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it != minElement)
        ++it;
    mainChain.insert(it, associatedSmall);

    std::deque<bool> inserted(pairs.size(), false);
    inserted[indexOfMinPair] = true;

	//5)jacobsthal
    insertSortedChainDeque(pairs, mainChain, inserted);

    
    if (hasOdd) 
    {
        std::deque<int>::iterator it = mainChain.begin();
        while (it != mainChain.end() && *it < oddElement)
            ++it;
        mainChain.insert(it, oddElement);
    }

    
    deq = mainChain;
}

void PmergeMe::insertSortedChainDeque(std::deque<std::pair<int, int> >& pairs, std::deque<int>& result, std::deque<bool>& inserted) 
{
    std::vector<int> jacobsthalSequence = getJacobsthalSequence(pairs.size());
    
    for (size_t i = 0; i < jacobsthalSequence.size(); ++i) 
    {
        int idx = jacobsthalSequence[i];
        if (idx < static_cast<int>(pairs.size()) && !inserted[idx]) 
        {
            std::deque<int>::iterator it = result.begin();
            while (it != result.end() && *it < pairs[idx].second)
                ++it;
            result.insert(it, pairs[idx].second);
            inserted[idx] = true;
        }
    }
	for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (!inserted[i]) 
        {
            std::deque<int>::iterator it = result.begin();
            while (it != result.end() && *it < pairs[i].second)
                ++it;
            result.insert(it, pairs[i].second);
        }
    }
}


std::vector<int> PmergeMe::getJacobsthalSequence(int n) 
{
    std::vector<int> sequence;
    
    std::vector<int> jacobsthalNumbers;
    jacobsthalNumbers.push_back(0);
    jacobsthalNumbers.push_back(1);
    
    int i = 2;
    while (jacobsthalNumbers.back() < n) 
    {
        jacobsthalNumbers.push_back(jacobsthalNumbers[i-1] + 2 * jacobsthalNumbers[i-2]);
        i++;
    }
    for (size_t j = 1; j < jacobsthalNumbers.size(); ++j) 
    {
        int curr = jacobsthalNumbers[j];
        int prev = jacobsthalNumbers[j-1];

        for (int k = curr; k > prev; --k)
            sequence.push_back(k);
    }
    
    return sequence;
}

// affichage
void PmergeMe::displayResults() const 
{

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
    
    // Afficher les temps d'exécution
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << _deqTime << " us" << std::endl;
}
