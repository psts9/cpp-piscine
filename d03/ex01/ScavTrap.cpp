#include <iostream>
#include <cstdlib>

#include "ScavTrap.hpp"

//~--------------------------------------------------------~
// Constructors

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

ScavTrap::ScavTrap(void) : name_("default")
{
	init();

	return;
}

ScavTrap::ScavTrap(std::string const& name) : name_(name)
{
	init();

	return;
}

ScavTrap::ScavTrap(ScavTrap const& scavTrap)
{
	*this = scavTrap;
	std::cout << "ScavTrap: " << this->name_ << ": Copy constructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Destructors

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: " << this->name_ << ": Destructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// ScavTrap

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

void	ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int	totalDamage = 0;

	if (this->armorDamageReduction_ > amount)
		totalDamage = 0;
	else
		totalDamage = amount - this->armorDamageReduction_;

	unsigned int	trueDamage = totalDamage;

	if (this->hitPoints_ < totalDamage)
		this->hitPoints_ = 0;
	else
		this->hitPoints_ -= totalDamage;

	std::cout   	 <<
	this->name_ 	 << " took "							   <<
	trueDamage		 << " points of damage, leaving him with " <<
	this->hitPoints_ << " points of health"					   <<
	std::endl;

	return;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints_ + amount > this->maxHitPoints_)
		this->hitPoints_ = this->maxHitPoints_;
	else
		this->hitPoints_ += amount;

	std::cout		 <<
	this->name_		 << " was repaired for "     	 <<
	amount			 << " points, leaving him with " <<
	this->hitPoints_ << " points of health"		 	 <<
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

//~--------------------------------------------------------~
// Get

std::string		ScavTrap::getName(void) const
{
	return (this->name_);
}

unsigned int	ScavTrap::getLevel(void) const
{
	return (this->level_);
}

unsigned int	ScavTrap::getHitPoints(void) const
{
	return (this->hitPoints_);
}

unsigned int	ScavTrap::getEnergyPoints(void) const
{
	return (this->energyPoints_);
}

unsigned int	ScavTrap::getMaxHitPoints(void) const
{
	return (this->maxHitPoints_);
}

unsigned int	ScavTrap::getMaxEnergyPoints(void) const
{
	return (this->maxEnergyPoints_);
}

unsigned int	ScavTrap::getMeleeAttackDamage(void) const
{
	return (this->meleeAttackDamage_);
}

unsigned int	ScavTrap::getRangedAttackDamage(void) const
{
	return (this->rangedAttackDamage_);
}

unsigned int	ScavTrap::getArmorDamageReduction(void) const
{
	return (this->armorDamageReduction_);
}

//~--------------------------------------------------------~
// Operators

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
{
	this->name_					= rhs.getName();
	this->level_				= rhs.getLevel();
	this->hitPoints_			= rhs.getHitPoints();
	this->energyPoints_ 		= rhs.getEnergyPoints();
	this->maxHitPoints_			= rhs.getMaxHitPoints();
	this->maxEnergyPoints_		= rhs.getMaxEnergyPoints();
	this->meleeAttackDamage_	= rhs.getMeleeAttackDamage();
	this->rangedAttackDamage_	= rhs.getRangedAttackDamage();
	this->armorDamageReduction_ = rhs.getArmorDamageReduction();

	return (*this);
}
