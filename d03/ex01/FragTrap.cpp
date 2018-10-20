#include <iostream>
#include <cstdlib>

#include "FragTrap.hpp"

//~--------------------------------------------------------~
// Constructors

void	FragTrap::init(void)
{
	std::cout << "FragTrap: " << this->name_ << ": Constructor called" << std::endl;

	this->level_ = 1;

	this->hitPoints_	= 100;
	this->energyPoints_	= 100;
	
	this->maxHitPoints_		= 100;
	this->maxEnergyPoints_	= 100;

	this->meleeAttackDamage_	= 30;
	this->rangedAttackDamage_	= 20;
	
	this->armorDamageReduction_	= 5;

	return;
}

FragTrap::FragTrap(void) : name_("default")
{
	init();

	return;
}

FragTrap::FragTrap(std::string const& name) : name_(name)
{
	init();

	return;
}

FragTrap::FragTrap(FragTrap const& fragTrap)
{
	*this = fragTrap;
	std::cout << "FragTrap: " << this->name_ << ": Copy constructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Destructors

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: " << this->name_ << ": Destructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// FragTrap

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

void	FragTrap::takeDamage(unsigned int amount)
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

void	FragTrap::beRepaired(unsigned int amount)
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

//~--------------------------------------------------------~
// Get

std::string		FragTrap::getName(void) const
{
	return (this->name_);
}

unsigned int	FragTrap::getLevel(void) const
{
	return (this->level_);
}

unsigned int	FragTrap::getHitPoints(void) const
{
	return (this->hitPoints_);
}

unsigned int	FragTrap::getEnergyPoints(void) const
{
	return (this->energyPoints_);
}

unsigned int	FragTrap::getMaxHitPoints(void) const
{
	return (this->maxHitPoints_);
}

unsigned int	FragTrap::getMaxEnergyPoints(void) const
{
	return (this->maxEnergyPoints_);
}

unsigned int	FragTrap::getMeleeAttackDamage(void) const
{
	return (this->meleeAttackDamage_);
}

unsigned int	FragTrap::getRangedAttackDamage(void) const
{
	return (this->rangedAttackDamage_);
}

unsigned int	FragTrap::getArmorDamageReduction(void) const
{
	return (this->armorDamageReduction_);
}

//~--------------------------------------------------------~
// Operators

FragTrap& FragTrap::operator=(FragTrap const& rhs)
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
