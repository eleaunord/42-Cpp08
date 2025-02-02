#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_tab = rhs._tab;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int nb)
{
	if (nb < INT_MIN || nb > INT_MAX)
		throw OverflowException();

	if (_tab.size() >= _N)
		throw FullSpanException();
	_tab.push_back(nb);
}

// more practical than addNumber() : accepting an iterator range
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_tab.size() + std::distance(begin, end) > _N) // STL ALGO
		throw FullSpanException();

	_tab.insert(_tab.end(), begin, end);
}

unsigned int Span::shortestSpan()
{
	if (this->_tab.size() < 2)
		throw NotEnoughElements();

	// sorting the array
	std::vector<int> sortedTab = _tab;
	std::sort(sortedTab.begin(), sortedTab.end()); // STL ALGO

	unsigned int minSpan = sortedTab[1] - sortedTab[0];

	for (size_t i = 1; i < sortedTab.size() - 1; i++)
	{
		unsigned int diff = sortedTab[i + 1] - sortedTab[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

unsigned int Span::longestSpan()
{
	if (this->_tab.size() < 2)
		throw NotEnoughElements();

	// starting point
	if (_tab.size() < 2)
		throw NotEnoughElements();

	int min = *std::min_element(_tab.begin(), _tab.end()); // STL ALGO
	int max = *std::max_element(_tab.begin(), _tab.end()); // STL ALGO

	return max - min;
}