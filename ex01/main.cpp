#include "Span.hpp"

// // test from the subject
// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }

int main()
{
	try
	{
		
		{
			std::cout << "\nbasic tests :" << std::endl;
			Span sp(5);
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // expected: 2 (9 and 11)
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;	  // expected: 14 (3 and 17)
		}
		{
			std::cout << "\ntests to check exception throwing :" << std::endl;
			try
			{
				Span sp(5);
				sp.addNumber(5);
				sp.addNumber(3);
				sp.addNumber(17);
				sp.addNumber(9);
				sp.addNumber(11);
				sp.addNumber(42); // throw FullSpanException
			}
			catch (const std::exception &e)
			{
				std::cerr << "Exception: " << e.what() << std::endl;
			}

			try
			{
				Span emptySpan(1);
				emptySpan.shortestSpan(); // throw NotEnoughElements exception
			}
			catch (const std::exception &e)
			{
				std::cerr << "Exception: " << e.what() << std::endl;
			}
		}
		{
			std::cout << "\nperformance test : " << std::endl;
			Span largeSpan(10000);
			for (int i = 0; i < 10000; i++)
			{
				largeSpan.addNumber(rand());
			}

			std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl;
		}
		{
			std::cout << "\naddNumbers() aka addNumber() with iterator range test :" << std::endl;
			Span bulkSpan(10);
			std::vector<int> numbers;
			numbers.push_back(1);
			numbers.push_back(2);
			numbers.push_back(3);
			numbers.push_back(4);
			numbers.push_back(5);
			numbers.push_back(6);
			numbers.push_back(7);
			numbers.push_back(8);
			numbers.push_back(9);
			numbers.push_back(10);

			bulkSpan.addNumbers(numbers.begin(), numbers.end());

			std::cout << "Shortest Span: " << bulkSpan.shortestSpan() << std::endl; // expected: 1
			std::cout << "Longest Span: " << bulkSpan.longestSpan() << std::endl;	// expected: 9
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected Exception: " << e.what() << std::endl;
	}

	return 0;
}
