#ifndef SPAN_HPP
#define SPAN_HPP

#include <limits.h>
#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

class Span{

	private :
		unsigned int _N;
		std::vector<int> _tab;

	public :

		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &rhs);
		~Span();


		void addNumber(int nb);
		unsigned int longestSpan();
		unsigned int shortestSpan();
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		// custom exceptions
		class OverflowException : public std::exception
		{
		public:
			const char *what() const throw() { return "Overflow detected!"; }
		};

		class FullSpanException : public std::exception
		{
		public:
			const char *what() const throw() { return "Span is already full!"; }
		};

		class NotEnoughElements : public std::exception
		{
		public:
			const char *what() const throw() { return "Not enough elements stored to find out the distance!"; }
		};
};
#endif