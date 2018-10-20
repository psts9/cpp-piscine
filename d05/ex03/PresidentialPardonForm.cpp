#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

PresidentialPardonForm::PresidentialPardonForm(void) :
	Form("Presidential Pardon Form", 25, 5), target_("default")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
	Form("Presidential Pardon Form", 25, 5), target_(target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& form) :
	Form(form.getName(), form.getSignGrade(), form.getExecuteGrade()), target_("default")
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	PresidentialPardonForm::execute(Bureaucrat const& bureaucrat) const
{
	try
	{
		Form::tryExecute(bureaucrat);

		executePresidentialPardonForm();
	}
	catch (std::exception& e)
	{
		throw;
	}
}

void	PresidentialPardonForm::executePresidentialPardonForm(void) const
{
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;

	return;
}
