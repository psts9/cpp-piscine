#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern it;
	Bureaucrat mike("mike", 1);

	Form* rrf;

	rrf = it.makeForm("shrubbery creation", "Blender");

	mike.signForm(*rrf);
	mike.executeForm(*rrf);

	std::cout << std::endl;

	Bureaucrat guy("guy", 1);

	rrf = it.makeForm("presidential pardon", "Jon Kanon");

	guy.executeForm(*rrf);
	guy.signForm(*rrf);
	guy.executeForm(*rrf);

	std::cout << std::endl;
	{
		Bureaucrat man("man", 150);

		rrf = it.makeForm("robotomy request", "Julebrus Kongen");

		man.signForm(*rrf);
	}
	{
		Bureaucrat man("man", 1);

		rrf = it.makeForm("robotomy request", "Julebrus Kongen");
		RobotomyRequestForm form3("dude");

		man.signForm(*rrf);
		man.executeForm(*rrf);
		man.executeForm(*rrf);
		man.executeForm(*rrf);
		man.executeForm(*rrf);
	}

	std::cout << std::endl;

	it.makeForm("haha", "john");

	return (0);
}
