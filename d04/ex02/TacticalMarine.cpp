#include <iostream>

#include "TacticalMarine.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

TacticalMarine::TacticalMarine(void)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;

	return;
}

TacticalMarine::TacticalMarine(TacticalMarine& marine)
{
	*this = marine;

	std::cout << "Tactical Marine ready for battle" << std::endl;

	return;
}

TacticalMarine::~TacticalMarine(void)
{
	std::cout << "Aaargh ..." << std::endl;

	return;
}

//~--------------------------------------------------------~
// Operators

TacticalMarine& TacticalMarine::operator=(TacticalMarine& marine)
{
	return (marine);
}

//~--------------------------------------------------------~
// Functions

ISpaceMarine* TacticalMarine::clone(void) const
{
	ISpaceMarine* marine = new TacticalMarine();

	return (marine);
}

void	TacticalMarine::battleCry(void) const
{
	std::cout << "For the holy PLOT !" << std::endl;

	return;
}

void	TacticalMarine::rangedAttack(void) const
{
	std::cout << "* attacks with bolter *" << std::endl;

	return;
}

void	TacticalMarine::meleeAttack(void) const
{
	std::cout << "* attacks with chainsword *" << std::endl;

	return;
}
