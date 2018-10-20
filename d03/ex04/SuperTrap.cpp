#include <iostream>

#include "SuperTrap.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

void	SuperTrap::init(std::string const& name)
{
	this->name_ = name;

	std::cout << "SuperTrap: " << this->name_ << ": Constructor called" << std::endl;

	this->level_ = 1;

	this->hitPoints_	= 100;
	this->energyPoints_	= 120;

	this->maxHitPoints_		= 100;
	this->maxEnergyPoints_	= 120;

	this->meleeAttackDamage_	= 60;
	this->rangedAttackDamage_	= 20;
	
	this->armorDamageReduction_	= 5;

	return;
}

SuperTrap::SuperTrap(void)
{
	init("default");

	return;
}

SuperTrap::SuperTrap(std::string const& name)
{
	init(name);

	return;
}

SuperTrap::SuperTrap(SuperTrap const& superTrap)
{
	*this = superTrap;
	std::cout << "SuperTrap: " << this->name_ << ": Copy constructor called" << std::endl;

	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap: " << this->name_ << ": Destructor called" << std::endl;

	return;
}
