#include <algorithm>
#include <vector>
#include <iostream>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;

	v.push_back(3);
	v.push_back(0);
	v.push_back(8);
	v.push_back(13);
	v.push_back(21);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 8);
		std::cout << *it << std::endl;
		it = easyfind(v, -1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::vector<int>::iterator beg;
	std::vector<int>::iterator end = v.end();

	for (beg = v.begin(); beg != end; ++beg)
	{
		std::cout << *beg << std::endl;
	}

	return (0);
}
