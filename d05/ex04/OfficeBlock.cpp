#include <cstdlib>

#include "OfficeBlock.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

OfficeBlock::OfficeBlock(void) :
	intern_(NULL), signer_(NULL), executer_(NULL)
{
	return;
}

OfficeBlock::OfficeBlock(Intern* intern, Bureaucrat* signer, Bureaucrat* executer) :
	intern_(intern), signer_(signer), executer_(executer)
{
	return;
}

OfficeBlock::~OfficeBlock(void)
{
	return;
}

//~--------------------------------------------------------~
// Exceptions

OfficeBlock::NoInternException::NoInternException(void)
{
	return;
}

OfficeBlock::NoInternException::~NoInternException(void) _NOEXCEPT
{
	return;
}

OfficeBlock::NoSigningBureaucratException::NoSigningBureaucratException(void)
{
	return;
}

OfficeBlock::NoSigningBureaucratException::~NoSigningBureaucratException(void) _NOEXCEPT
{
	return;
}

OfficeBlock::NoExecutingBureaucratException::NoExecutingBureaucratException(void)
{
	return;
}

OfficeBlock::NoExecutingBureaucratException::~NoExecutingBureaucratException(void) _NOEXCEPT
{
	return;
}

const char* OfficeBlock::NoInternException::what(void) const throw()
{
	return ("Office Block does not contain an intern");
}

const char* OfficeBlock::NoSigningBureaucratException::what(void) const throw()
{
	return ("Office Block has no signing bureaucrat");
}

const char* OfficeBlock::NoExecutingBureaucratException::what(void) const throw()
{
	return ("Office Block has no executing bureaucrat");
}

//~--------------------------------------------------------~
// Sets

void	OfficeBlock::setIntern(Intern* intern)
{
	intern_ = intern;

	return;
}

void	OfficeBlock::setSigner(Bureaucrat* signer)
{
	signer_ = signer;

	return;
}

void	OfficeBlock::setExecuter(Bureaucrat* executer)
{
	executer_ = executer;

	return;
}

//~--------------------------------------------------------~
// Functions

void	OfficeBlock::doBureaucracy(std::string const& type, std::string const& target)
{
	Form *form;

	try
	{
		if (intern_ == NULL)
			throw(OfficeBlock::NoInternException());
		if (signer_ == NULL)
			throw(OfficeBlock::NoSigningBureaucratException());
		if (executer_ == NULL)
			throw(OfficeBlock::NoExecutingBureaucratException());

		form = intern_->makeForm(type, target);
		signer_->signForm(*form);
		executer_->executeForm(*form);
	}
	catch (std::exception& e)
	{
		throw;
	}
}
