#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

/*

std::stack est un conteneur très pratique, mais il n’a pas d’itérateurs. Cela veut dire qu’on ne peut pas parcourir ses éléments avec une boucle for comme on le ferait avec std::vector ou std::list.
Comme std::stack utilise un conteneur interne (std::deque par défaut), on va rendre ce conteneur accessible pour pouvoir itérer dessus.
On va hériter de std::stack et ajouter des fonctions begin() et end() qui retourneront des itérateurs du conteneur interne.


extend std::stack to make it iterable aka as it is in STL rn we cannot loop it
std::stack<T> is a container adapter aka it is not a container itself but uses an underlying container (default: std::deque<T>).
Stack supports: push(), pop(), top(), size(), empty()
Stack does NOT support: Iterators (begin(), end())
*/

#include <stack>
#include <iostream>
#include <deque>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> // std::stack<T> internally uses a container (std::deque<T> by default), we retrieve iterators from that container.
{
	public :

		// contructors

		MutantStack() {};

		MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy){}

		MutantStack &operator=(const MutantStack<T> &rhs)
		{
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}

		~MutantStack() {};


		// methods

		// Iterator support: Expose iterators from the underlying container
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{ 
			return this->c.begin(); // this->c to access the underlying container's iterators
		}
		iterator end()
		{
			return this->c.end(); // this->c to access the underlying container's iterators
		}

};

#endif