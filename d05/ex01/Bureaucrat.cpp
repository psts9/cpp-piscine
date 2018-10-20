#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Bureaucrat::Bureaucrat(void) : 
	name_("default"), grade_(1)
{
	return;
}

Bureaucrat::Bureaucrat(std::string const& name, unsigned short grade) : 
	name_(name), grade_(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());

	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const& bureaucrat) : 
	name_(bureaucrat.getName()), grade_(bureaucrat.getGrade())
{
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << name_ << ", destructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Operators

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& bureaucrat)
{
	grade_ = bureaucrat.getGrade();

	return (*this);
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;

	return (o);
}

//~--------------------------------------------------------~
// Gets

std::string const&	Bureaucrat::getName(void) const
{
	return (name_);
}

unsigned short		Bureaucrat::getGrade(void) const
{
	return (grade_);
}

//~--------------------------------------------------------~
// Functions

void	Bureaucrat::incGrade(void)
{
	if (grade_ <= 1)
		throw (Bureaucrat::GradeTooHighException());

	--grade_;

	return;
}

void	Bureaucrat::decGrade(void)
{
	if (grade_ >= 150)
		throw (Bureaucrat::GradeTooLowException());

	++grade_;

	return;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);

		std::cout << name_ << " signs " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name_ << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}

	return;
}

//~--------------------------------------------------------~
// Exceptions

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
	return;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) _NOEXCEPT
{
	return;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
	return;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) _NOEXCEPT
{
	return;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}
