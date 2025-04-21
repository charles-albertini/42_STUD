#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <list>


template<typename T>
class MutantStack : public std::stack<T>
{
	public:

	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other);
	virtual ~MutantStack();

	typedef typename std::stack<T>::container_type::iterator 		       iterator;
    typedef typename std::stack<T>::container_type::const_iterator         const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator 	   reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	//fonctions
	iterator begin();
	iterator end();
	const_iterator begin() const;
    const_iterator end() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

/*
iterator: parcour et modifie les element du conteneur du debut a la fin
const_iterator : meme chose mais ne peut pas modifier
reverse_iterator : de la fin vers le debut
const revers iterator: meme chose mas modifie pas 
*/
#endif