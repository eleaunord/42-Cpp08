#include "easyfind.hpp"

int main()
{
	{
		try
		{
			// Use push_back() instead of initializer lists (not supported in C++98)
			std::vector<int> vec;
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);
			vec.push_back(5);

			std::cout << "Found in vector: " << *easyfind(vec, 3) << std::endl;
			std::cout << "Found in vector: " << *easyfind(vec, -1) << std::endl;
			std::cout << "Found in vector: " << *easyfind(vec, 2) << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		try
		{
			// Use push_back() for list instead of initializer lists
			std::list<int> lst;
			lst.push_back(10);
			lst.push_back(20);
			lst.push_back(30);
			lst.push_back(40);
			lst.push_back(50);

			std::cout << "Found in list: " << *easyfind(lst, 20) << std::endl;
			std::cout << "Found in list: " << *easyfind(lst, 100) << std::endl;
			std::cout << "Found in list: " << *easyfind(lst, 50) << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	return 0;
}
