#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat mike("mike", 1);

	ShrubberyCreationForm form1("dude");

	mike.signForm(form1);
	mike.executeForm(form1);

	std::cout << std::endl;

	Bureaucrat guy("guy", 1);

	PresidentialPardonForm form2("dude");

	guy.executeForm(form2);
	guy.signForm(form2);
	guy.executeForm(form2);

	std::cout << std::endl;
	{
		Bureaucrat man("man", 150);

		RobotomyRequestForm form3("dude");

		man.signForm(form3);
	}
	{
		Bureaucrat man("man", 1);

		RobotomyRequestForm form3("dude");

		man.signForm(form3);
		man.executeForm(form3);
		man.executeForm(form3);
		man.executeForm(form3);
		man.executeForm(form3);
	}

	return (0);
}
