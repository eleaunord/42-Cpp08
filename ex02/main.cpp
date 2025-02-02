#include "MutantStack.hpp"

// from the subject
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

int main()
{
	{
		std::cout << "my MutantStack :\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "top (élément le plus haut de la pile aka le dernier ajouté): " << mstack.top() << std::endl; // Affiche 17
		mstack.pop(); // supprime 17
		std::cout << "Taille après pop: " << mstack.size() << std::endl; // Affiche 1
		// règle last in first out bien respecté de std::stack<int>

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << "Éléments de MutantStack:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	{
		std::cout << "\nComparaison with std::list who has an iterator\n";
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		lst.pop_back(); // pour faire comme std::stack<int> même si en soit  vu que c'est une liste on peutaccéder aux éléments dans n'importe quel ordre avec des itérateurs.
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::cout << std::endl;
		
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		std::cout << "Éléments de std::list:\n";
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	return 0;
}
