#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	std::cout << std::endl;
	std::cout << std::endl;

	Form form("cool form", 87, 2);

	std::cout << form << std::endl;

	try
	{
		guy.signForm(form);
		std::cout << form;
		mike.signForm(form);
		std::cout << std::endl;
		form.beSigned(mike);
		std::cout << "yo" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form form("guy", -1, 1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Form form2("exclusive form", 1, 1);
	std::cout << form2;

	try
	{
		form2.beSigned(mike);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << form2 << std::endl;
	}

	return (0);
}
