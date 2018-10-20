#include <iostream>
#include <cstdlib>

#include "ClapTrap.hpp"

//~--------------------------------------------------------~
// Constructors

void	ClapTrap::init(void)
{
	std::cout << "ClapTrap: " << this->name_ << ": Constructor called" << std::endl;

	this->level_ = 1;

	this->hitPoints_	= 100;
	this->energyPoints_	= 100;
	
	this->maxHitPoints_		= 100;
	this->maxEnergyPoints_	= 100;

	this->meleeAttackDamage_	= 100;
	this->rangedAttackDamage_	= 100;
	
	this->armorDamageReduction_	= 100;

	return;
}

ClapTrap::ClapTrap(void) : name_("default")
{
	init();

	return;
}

ClapTrap::ClapTrap(std::string const& name) : name_(name)
{
	init();

	return;
}

ClapTrap::ClapTrap(ClapTrap const& clapTrap)
{
	*this = clapTrap;
	std::cout << "ClapTrap: " << this->name_ << ": Copy constructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Destructors

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: " << this->name_ << ": Destructor called" << std::endl;

	return;
}

//~--------------------------------------------------------~
// ClapTrap

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
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

//~--------------------------------------------------------~
// Get

std::string		ClapTrap::getName(void) const
{
	return (this->name_);
}

unsigned int	ClapTrap::getLevel(void) const
{
	return (this->level_);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints_);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints_);
}

unsigned int	ClapTrap::getMaxHitPoints(void) const
{
	return (this->maxHitPoints_);
}

unsigned int	ClapTrap::getMaxEnergyPoints(void) const
{
	return (this->maxEnergyPoints_);
}

unsigned int	ClapTrap::getMeleeAttackDamage(void) const
{
	return (this->meleeAttackDamage_);
}

unsigned int	ClapTrap::getRangedAttackDamage(void) const
{
	return (this->rangedAttackDamage_);
}

unsigned int	ClapTrap::getArmorDamageReduction(void) const
{
	return (this->armorDamageReduction_);
}

//~--------------------------------------------------------~
// Operators

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
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
