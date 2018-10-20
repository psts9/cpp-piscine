#include <iostream>

#include "SuperMutant.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

SuperMutant::SuperMutant(void) :
	Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;

	return;
}

SuperMutant::SuperMutant(int hp, std::string const& type) :
	Enemy(hp, type)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;

	return;
}

SuperMutant::SuperMutant(SuperMutant const& superMutant) :
	Enemy(superMutant.getHP(), superMutant.getType())
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;

	return;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;

	return;
}

//~--------------------------------------------------------~
// Functions

void	SuperMutant::takeDamage(int amount)
{
	if (amount - 3 < 0)
		return;
	
	this->hp_ -= amount - 3;

	return;
}
