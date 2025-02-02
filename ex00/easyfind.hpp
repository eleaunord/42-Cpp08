#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

// containers
#include <vector>
#include <list>
#include <map>

#include <algorithm>
#include <stdexcept>

// T est un container d'ENTIERS

template <typename T>
typename T::iterator easyfind(T &container, const int value)
{
	// std::find from <algorithm> used to look up the value in container
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	
	if (it == container.end())
		throw(std::out_of_range("can't find the needle in the haystack!"));

	return (it);
}


#endif