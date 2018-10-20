#include <iostream>

#include "CentralBureaucracy.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

CentralBureaucracy::CentralBureaucracy(void)
{
	officeBlockCount_ = 0;
	queueCounter_ = 0;
	bureaucratCount_ = 0;

	return;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
	return;
}

//~--------------------------------------------------------~
// Exceptions

CentralBureaucracy::FullTargetQueueException::FullTargetQueueException(void)
{
	return;
}

CentralBureaucracy::FullTargetQueueException::~FullTargetQueueException(void) _NOEXCEPT
{
	return;
}

CentralBureaucracy::FullBureaucratQueueException::FullBureaucratQueueException(void)
{
	return;
}

CentralBureaucracy::FullBureaucratQueueException::~FullBureaucratQueueException(void) _NOEXCEPT
{
	return;
}

const char*	CentralBureaucracy::FullTargetQueueException::what(void) const throw()
{
	return ("The target queue is full");
}

const char* CentralBureaucracy::FullBureaucratQueueException::what(void) const throw()
{
	return ("The bureaucrat queue is full");
}

//~--------------------------------------------------------~
// Functions

void	CentralBureaucracy::queueUp(std::string const& target)
{
	if (queueCounter_ < 512)
	{
		targetQueue_[queueCounter_] = target;
		++queueCounter_;
	}
	else
	{
		throw (CentralBureaucracy::FullTargetQueueException());
	}

	return;
}

void	CentralBureaucracy::addBureaucrat(Bureaucrat* bureaucrat)
{
	if (bureaucratCount_ < 40)
	{
		bureaucrats_[bureaucratCount_] = bureaucrat;
		++bureaucratCount_;
	}
	else
	{
		throw (CentralBureaucracy::FullBureaucratQueueException());
	}

	return;
}

std::string const g_forms[] =
{
	"robotomy request",
	"presidential pardon"
};

// 	"shrubbery creation"

void	CentralBureaucracy::doBureaucracy(void)
{
	officeBlockCount_ = bureaucratCount_ / 2;

	for (int i = 0; i < officeBlockCount_; ++i)
	{
		try
		{
			officeBlocks_[i].setIntern(new Intern);
			officeBlocks_[i].setSigner(bureaucrats_[i * 2]);
			officeBlocks_[i].setExecuter(bureaucrats_[i * 2 + 1]);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	for (int i = 0; i < queueCounter_; ++i)
	{
		int j = 0;
		while (j < officeBlockCount_ && i < queueCounter_)
		{
			try
			{
				officeBlocks_[j].doBureaucracy(g_forms[rand() % 2],targetQueue_[i]);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
			++j;
			++i;
		}
	}

	return;
}
