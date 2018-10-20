#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form("Shrubbery Creation Form", 145, 137), target_("default")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
	Form("Shrubbery Creation Form", 145, 137), target_(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& form) :
	Form(form.getName(), form.getSignGrade(), form.getExecuteGrade()), target_("default")
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	ShrubberyCreationForm::execute(Bureaucrat const& bureaucrat) const
{
	try 
	{
		Form::tryExecute(bureaucrat);

		executeShrubberyCreationForm();
	}
	catch (std::exception& e)
	{
		throw;
	}
}

void	ShrubberyCreationForm::executeShrubberyCreationForm(void) const
{
	std::string fileName = target_ + "_shrubbery";
	std::ofstream outStream;

	outStream.open(fileName);

	for (int i = 0; i < 5; ++i)
	{
		outStream << "       _-_" << std::endl;
		outStream << "    /~~   ~~\\" << std::endl;
		outStream << " /~~         ~~\\" << std::endl;
		outStream << "{               }" << std::endl;
		outStream << " \\  _-     -_  /" << std::endl;
		outStream << "   ~  \\\\ //  ~" << std::endl;
		outStream << "_- -   | | _- _" << std::endl;
		outStream << "  _ -  | |   -_" << std::endl;
		outStream << "      // \\\\" << std::endl;
		outStream << std::endl;
	}

	outStream.close();

	return;
}
