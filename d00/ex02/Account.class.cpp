#include <ctime>
#include <iostream>
#include <iomanip>

#include "Account.class.hpp"

int		Account::_nbAccounts;
int		Account::_totalAmount;
int		Account::_totalNbDeposits;
int		Account::_totalNbWithdrawals;

void	Account::_displayTimestamp(void)
{
	std::time_t	t	 = std::time(0);
	std::tm		*now = std::localtime(&t);

	std::cout << '['											<<
	std::setw(4) << std::setfill('0') << (now->tm_year + 1900)	<<
	std::setw(2) << std::setfill('0') << (now->tm_mon + 1)		<<
	std::setw(2) << std::setfill('0') << (now->tm_mday)			<<
	'_'															<<
	std::setw(2) << std::setfill('0') << (now->tm_hour)			<<
	std::setw(2) << std::setfill('0') << (now->tm_min)			<<
	std::setw(2) << std::setfill('0') << (now->tm_sec)			<<
				 ']' << ' ';

	return;
}

void		Account::displayStatus(void) const
{
	this->_displayTimestamp();

	std::cout      <<
	"index:"       << this->_accountIndex  << ';' <<
	"amount:"      << this->_amount	       << ';' <<
	"deposits:"    << this->_nbDeposits    << ';' <<
	"withdrawals:" << this->_nbWithdrawals <<
	std::endl;

	return;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex		=  Account::_nbAccounts;
	this->_nbAccounts		+= 1;
	this->_totalAmount		+= initial_deposit;
	this->_amount			=  initial_deposit;
	this->_nbDeposits		=  0;
	this->_nbWithdrawals	=  0;

	this->_displayTimestamp();

	std::cout <<
	"index:"  << this->_accountIndex << ';' <<
	"amount:" << this->_amount		 << ';' <<
	"created"						 <<
	std::endl;

	return;
}

Account::~Account(void)
{
	this->_nbAccounts	-= 1;
	this->_totalAmount	-= this->_amount;

	this->_displayTimestamp();

	std::cout <<
	"index:"  << this->_accountIndex << ';' <<
	"amount:" << this->_amount		 << ';' <<
	"closed"						 <<
	std::endl;

	return;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	std::cout      <<
	"accounts:"    << Account::_nbAccounts    		<< ';' <<
	"total:"	   << Account::_totalAmount  		<< ';' <<
	"deposits:"    << Account::_totalNbDeposits		<< ';' <<
	"withdrawals:" << Account::_totalNbWithdrawals	<<
	std::endl;

	return;
}

void		Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;

	this->_totalAmount			+= deposit;
	this->_totalNbDeposits		+= 1;
	this->_amount				+= deposit;
	this->_nbDeposits			+= 1;

	this->_displayTimestamp();

	std::cout		<<
	"index:"		<< this->_accountIndex	<< ';' <<
	"p_amount:"		<< p_amount				<< ';' <<
	"deposit:"		<< deposit				<< ';' <<
	"amount:"		<< this->_amount		<< ';' <<
	"nb_deposits:"	<< this->_nbDeposits	<<
	std::endl;

	return;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	bool 	succeeded = true;
	int		p_amount  = this->_amount;

	if (withdrawal > this->_amount)
		succeeded = false;

	if (succeeded)
	{
		this->_totalAmount			-= withdrawal;
		this->_totalNbWithdrawals	+= 1;
		this->_amount				-= withdrawal;
		this->_nbWithdrawals		+= 1;
	}

	this->_displayTimestamp();

	std::cout		<<
	"index:"		<< this->_accountIndex	<< ';' <<
	"p_amount:"		<< p_amount				<< ';' <<
	"withdrawal:";
	
	if (succeeded)
	{
		std::cout			<< withdrawal			 << ';' <<
		"amount:"			<< this->_amount		 << ';' <<
		"nb_withdrawals:"	<< this->_nbWithdrawals;
	}
	else
		std::cout			<< "refused";

	std::cout << std::endl;

	return (succeeded);
}

int			Account::checkAmount(void) const
{
	return (this->_totalAmount);
}
