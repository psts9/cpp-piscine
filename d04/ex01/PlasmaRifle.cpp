#include <iostream>

#include "PlasmaRifle.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

PlasmaRifle::PlasmaRifle(void) :
	AWeapon("Plasma Rifle", 5, 21)
{
	return;
}

PlasmaRifle::PlasmaRifle(std::string const& name, int apcost, int damage) :
	AWeapon(name, apcost, damage)
{
	return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const& plasmaRifle) :
	AWeapon(plasmaRifle.getName(), plasmaRifle.getAPCost(), plasmaRifle.getDamage())
{
	return;
}

PlasmaRifle::~PlasmaRifle(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;

	return;
}
