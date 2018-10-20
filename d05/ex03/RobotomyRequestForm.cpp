#include <iostream>

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

RobotomyRequestForm::RobotomyRequestForm(void) :
	Form("Robotomy Request Form", 72, 45), target_("default")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
	Form("Robotomy Request Form", 145, 137), target_(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& form) :
	Form(form.getName(), form.getSignGrade(), form.getExecuteGrade()), target_("default")
{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	RobotomyRequestForm::execute(Bureaucrat const& bureaucrat) const
{
	try
	{
		Form::tryExecute(bureaucrat);

		executeRobotomyRequestForm();
	}
	catch (std::exception& e)
	{
		throw;
	}
}

void	RobotomyRequestForm::executeRobotomyRequestForm(void) const
{
	std::cout << "* drill drill *" << std::endl;

	if (rand() % 2 == 0)
	{
		std::cout << target_ << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "Disaster! " << target_ << " was not robotomized!" << std::endl;
	}

	return;
}
