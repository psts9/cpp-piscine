#include <iostream>

#include "PowerFist.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

PowerFist::PowerFist(void) :
	AWeapon("Power Fist", 8, 50)
{
	return;
}

PowerFist::PowerFist(std::string const& name, int apcost, int damage) :
	AWeapon(name, apcost, damage)
{
	return;
}

PowerFist::PowerFist(PowerFist const& powerFist) :
	AWeapon(powerFist.getName(), powerFist.getAPCost(), powerFist.getDamage())
{
	return;
}

PowerFist::~PowerFist(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;

	return;
}
