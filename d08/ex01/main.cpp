#include <iostream>

#include "span.hpp"

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		sp.addNumber(6);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span span = Span(1);

	span.addNumber(1);

	try
	{
		span.shortestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	Span m = Span(6);

	std::vector<int> v;

	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(2);

	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator end = v.end();

	try
	{
		m.addNumber(it, end);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Span d = Span(100);

	d.addNumber(it, end);

	std::cout << d.shortestSpan() << std::endl;
	std::cout << d.longestSpan() << std::endl;

	std::vector<int> dumb;


	Span g = Span(2000);

	for (int i = 0; i < 2000; ++i)
	{
		g.addNumber(i);
	}

	std::cout << g.shortestSpan() << std::endl;
	std::cout << g.longestSpan() << std::endl;


	return (0);
}
