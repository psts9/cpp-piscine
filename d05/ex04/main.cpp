#include <iostream>

#include "OfficeBlock.hpp"

int main(void)
{
	OfficeBlock	ob;

	try
	{
		ob.doBureaucracy("shrubbery creation", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Intern* intern = new Intern;
	ob.setIntern(intern);

	try
	{
		ob.doBureaucracy("shrubbery creation", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat* signer = new Bureaucrat("thomas", 150);
	ob.setSigner(signer);

	try
	{
		ob.doBureaucracy("shrubbery creation", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat* executer = new Bureaucrat("guy", 150);
	ob.setExecuter(executer);

	try
	{
		ob.doBureaucracy("shrubbery creation", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat* signer2 = new Bureaucrat("better thomas", 1);
	ob.setSigner(signer2);

	try
	{
		ob.doBureaucracy("shrubbery creation", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat* executer2 = new Bureaucrat("better guy", 10);
	ob.setExecuter(executer2);

	try
	{
		ob.doBureaucracy("shrubbery creation", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		ob.doBureaucracy("not valid", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		ob.doBureaucracy("robotomy request", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		ob.doBureaucracy("presidential pardon", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat* executer3 = new Bureaucrat("best guy", 1);
	ob.setExecuter(executer3);

	try
	{
		ob.doBureaucracy("presidential pardon", "guy");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
