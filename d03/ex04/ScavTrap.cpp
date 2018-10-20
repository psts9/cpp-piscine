#include <iostream>
#include <cstdlib>

#include "ScavTrap.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

void	ScavTrap::init(void)
{
	std::cout << "ScavTrap: " << this->name_ << ": Constructor called" << std::endl;

	this->level_ = 1;

	this->hitPoints_	= 100;
	this->energyPoints_	= 50;

	this->maxHitPoints_		= 100;
	this->maxEnergyPoints_	= 50;

	this->meleeAttackDamage_	= 20;
	this->rangedAttackDamage_	= 15;

	this->armorDamageReduction_	= 3;

	return;
}

ScavTrap::ScavTrap(void)
{
	this->name_ = "default";
	init();

	return;
}

ScavTrap::ScavTrap(std::string const& name)
{
	this->name_ = name;
	init();

	return;
}

ScavTrap::ScavTrap(ScavTrap const& scavTrap)
{
	*this = scavTrap;
	std::cout << "ScavTrap: " << this->name_ << ": Copy constructor called" << std::endl;

	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: " << this->name_ << ": Destructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Functions

void	ScavTrap::rangedAttack(std::string const& target) const
{
	std::cout   <<
	this->name_ << " attacks " 				<<
	target		<< " at range, causing "	<<
	this->rangedAttackDamage_				<<
	" points of damage ! (ScavTrap)"		<<
	std::endl;

	return;
}

void	ScavTrap::meleeAttack(std::string const& target) const
{
	std::cout   <<
	this->name_ << " attacks " 				<<
	target		<< " with melee, causing "	<<
	this->meleeAttackDamage_				<<
	" points of damage ! (ScavTrap)"		<<
	std::endl;

	return;
}

void	ScavTrap::challengeNewcomer(std::string const& target)
{
	std::string const challenges[] =
	{
		"Play With Matches",
		"Die",
		"Road Rage",
		"Make A Friend",
		"Achieve Orbit"
	};

	std::cout 	<< 
	this->name_ << " challenges " 	<<
	target		<< " to "	    	<<
	challenges[rand() % 5]		    <<
	std::endl;

	return;
}
