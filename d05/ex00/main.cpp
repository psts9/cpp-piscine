#include <iostream>

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat mike("mike", 149);

	std::cout << mike << std::endl;

	try
	{
		mike.decGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << mike << std::endl;

	try
	{
		mike.decGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << mike << std::endl;

	Bureaucrat guy("guy", 2);

	std::cout << guy << std::endl;

	try
	{
		guy.incGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << guy << std::endl;

	try
	{
		guy.incGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << guy << std::endl;

	try
	{
		Bureaucrat albert("albert", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bigMike("big mike", 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
