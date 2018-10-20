#include <cstdlib>
#include <iostream>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Intern::Intern(void)
{
	return;
}

Intern::Intern(Intern& intern)
{
	*this = intern;

	return;
}

Intern::~Intern(void)
{
	return;
}

//~--------------------------------------------------------~
// Operators

Intern&	Intern::operator=(Intern& intern)
{
	return (intern);
}

//~--------------------------------------------------------~
// Exceptions

Intern::InvalidFormTypeException::InvalidFormTypeException(void)
{
	return;
}

Intern::InvalidFormTypeException::~InvalidFormTypeException(void) _NOEXCEPT
{
	return;
}

const char* Intern::InvalidFormTypeException::what(void) const throw()
{
	return ("Invalid form type");
}

//~--------------------------------------------------------~
// Functions

Form*	Intern::makeForm(std::string const& type, std::string const& target)
{
	Form* formPtr = NULL;

	try
	{
		if (type == "robotomy request")
			formPtr = new RobotomyRequestForm(target);
		else if (type == "presidential pardon")
			formPtr = new PresidentialPardonForm(target);
		else if (type == "shrubbery creation")
			formPtr = new ShrubberyCreationForm(target);
		else
			throw (Intern::InvalidFormTypeException());

		std::cout << "Intern creates " << type << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (formPtr);
}
