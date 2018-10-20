#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Form::Form(void) :
	name_("default"), signGrade_(1), executeGrade_(1), isSigned_(false)
{
	return;
}

Form::Form(std::string const& name, unsigned short signGrade, unsigned short executeGrade) :
	name_(name), signGrade_(signGrade), executeGrade_(executeGrade), isSigned_(false)
{
	if (signGrade_ < 1 || executeGrade_ < 1)
		throw (Form::GradeTooHighException());
	else if (signGrade_ > 150 || executeGrade_ > 150)
		throw (Form::GradeTooLowException());

	return;
}

Form::Form(Form const& form) :
	name_(form.getName()), signGrade_(form.getSignGrade()), executeGrade_(form.getExecuteGrade()), isSigned_(form.getIsSigned())
{
	return;
}

Form::~Form(void)
{
	return;
}

//~--------------------------------------------------------~
// Operators

Form& Form::operator=(Form const& form)
{
	isSigned_ = form.getIsSigned();

	return (*this);
}

std::ostream& operator<<(std::ostream& o, Form const& form)
{
	o << form.getName() <<
	", sign grade " << form.getSignGrade() << 
	", execute grade " << form.getExecuteGrade() << 
	". status: ";

	if (form.getIsSigned() == true)
	{
		o << "signed";
	}
	else
	{
		o << "not signed";
	}

	o << std::endl;

	return (o);
}

//~--------------------------------------------------------~
// Exceptions

Form::GradeTooHighException::GradeTooHighException(void)
{
	return;
}

Form::GradeTooHighException::~GradeTooHighException(void) _NOEXCEPT
{
	return;
}

Form::GradeTooLowException::GradeTooLowException(void)
{
	return;
}

Form::GradeTooLowException::~GradeTooLowException(void) _NOEXCEPT
{
	return;
}

Form::FormNotSignedException::FormNotSignedException(void)
{
	return;
}

Form::FormNotSignedException::~FormNotSignedException(void) _NOEXCEPT
{
	return;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

const char* Form::FormNotSignedException::what(void) const throw()
{
	return ("Form has not been signed");
}

//~--------------------------------------------------------~
// Gets

std::string const& Form::getName(void) const
{
	return (name_);
}

unsigned short Form::getSignGrade(void) const
{
	return (signGrade_);
}

unsigned short Form::getExecuteGrade(void) const
{
	return (executeGrade_);
}

bool	Form::getIsSigned(void) const
{
	return (isSigned_);
}

//~--------------------------------------------------------~
// Functions

void	Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade_)
		throw (Form::GradeTooLowException());
	else
		isSigned_ = true;

	return;
}

void	Form::tryExecute(Bureaucrat const& bureaucrat) const
{
	if (bureaucrat.getGrade() > executeGrade_)
		throw (Form::GradeTooLowException());
	else if (isSigned_ == false)
		throw (Form::FormNotSignedException());

	return;
}
