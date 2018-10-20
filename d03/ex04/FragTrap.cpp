#include <iostream>
#include <cstdlib>

#include "FragTrap.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

void	FragTrap::init(void)
{
	std::cout << "FragTrap: " << this->name_ << ": Constructor called" << std::endl;

	this->level_ = 1;

	this->hitPoints_	= 100;
	this->energyPoints_ = 100;

	this->maxHitPoints_		= 100;
	this->maxEnergyPoints_	= 100;

	this->meleeAttackDamage_	= 30;
	this->rangedAttackDamage_	= 20;

	this->armorDamageReduction_	= 5;

	return;
}

FragTrap::FragTrap(void)
{
	this->name_ = "default";
	init();

	return;
}

FragTrap::FragTrap(std::string const& name)
{
	this->name_ = name;
	init();

	return;
}

FragTrap::FragTrap(FragTrap const& fragTrap)
{
	*this = fragTrap;
	std::cout << "FragTrap: " << this->name_ << ": Copy constructor called" << std::endl;

	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: " << this->name_ << ": Destructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Functions

void	FragTrap::rangedAttack(std::string const& target) const
{
	std::cout   <<
	this->name_ << " attacks " 				<<
	target		<< " at range, causing "	<<
	this->rangedAttackDamage_				<<
	" points of damage ! (FragTrap)"		<<
	std::endl;

	return;
}

void	FragTrap::meleeAttack(std::string const& target) const
{
	std::cout   <<
	this->name_ << " attacks " 				<<
	target		<< " with melee, causing "	<<
	this->meleeAttackDamage_				<<
	" points of damage ! (FragTrap)"		<<
	std::endl;

	return;
}

void	FragTrap::vaulthunter_dot_exe(std::string const& target)
{
	std::string const attacks[] =
	{
		"Torgue Fiesta",
		"Pirate Ship Mode",
		"Clap-in-the-Box",
		"Gun Wizard",
		"One-Shot Wonder"
	};

	if (this->energyPoints_ < 25)
	{
		std::cout << this->name_ << " does not have enough energy"		<<
		     " (" << this->energyPoints_ << " energy points remaining)"	<<
		std::endl;
	
		return;
	}

	this->energyPoints_ -= 25;

	std::cout 	<< 
	this->name_ << " attacks "  <<
	target		<< " with "	    <<
	attacks[rand() % 5]		    <<
	" (" << this->energyPoints_ << " energy points remaining)" <<
	std::endl;

	return;
}
