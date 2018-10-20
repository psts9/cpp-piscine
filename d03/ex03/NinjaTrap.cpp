#include <iostream>
#include <cstdlib>

#include "NinjaTrap.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

void	NinjaTrap::init(std::string const& name)
{
	this->name_ = name;

	std::cout << "NinjaTrap: " << this->name_ << ": Constructor called" << std::endl;

	this->level_ = 1;

	this->hitPoints_	= 60;
	this->energyPoints_ = 120;

	this->maxHitPoints_		= 60;
	this->maxEnergyPoints_	= 120;

	this->meleeAttackDamage_	= 60;
	this->rangedAttackDamage_	= 5;

	this->armorDamageReduction_ = 0;

	return;
}

NinjaTrap::NinjaTrap(void)
{
	init("default");

	return;
}

NinjaTrap::NinjaTrap(std::string const& name)
{
	init(name);

	return;
}

NinjaTrap::NinjaTrap(NinjaTrap const& ninjaTrap)
{
	*this = ninjaTrap;
	std::cout << "NinjaTrap: " << this->name_ << ": Copy constructor called" << std::endl;

	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap: " << this->name_ << ": Destructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Functions

void	NinjaTrap::rangedAttack(std::string const& target) const
{
	std::cout   <<
	this->name_ << " attacks " 				<<
	target		<< " at range, causing "	<<
	this->rangedAttackDamage_				<<
	" points of damage ! (NinjaTrap)"		<<
	std::endl;

	return;
}

void	NinjaTrap::meleeAttack(std::string const& target) const
{
	std::cout   <<
	this->name_ << " attacks " 				<<
	target		<< " with melee, causing "	<<
	this->meleeAttackDamage_				<<
	" points of damage ! (NinjaTrap)"		<<
	std::endl;

	return;
}

void	NinjaTrap::ninjaShoebox(ClapTrap const& clapTrap)
{
	std::cout << "ClapTrap " << clapTrap.getName() << " does something funny" << std::endl;

	return;
}

void	NinjaTrap::ninjaShoebox(FragTrap const& fragTrap)
{
	std::cout << "FragTrap " << fragTrap.getName() << " does something really funny" << std::endl;

	return;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const& ninjaTrap)
{
	std::cout << "NinjaTrap " << ninjaTrap.getName() << " does something extremely funny" << std::endl;

	return;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const& scavTrap)
{
	std::cout << "ScavTrap " << scavTrap.getName() << " does the funniest thing possible ever" << std::endl;

	return;
}
