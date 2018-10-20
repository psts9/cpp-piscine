#include <iostream>

#include "AssaultTerminator.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

AssaultTerminator::AssaultTerminator(void)
{
	std::cout << "* teleports from space *" << std::endl;

	return;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator& marine)
{
	*this = marine;

	std::cout << "* teleports from space *" << std::endl;

	return;
}

AssaultTerminator::~AssaultTerminator(void)
{
	std::cout << "I'll be back ..." << std::endl;

	return;
}

//~--------------------------------------------------------~
// Operators

AssaultTerminator& AssaultTerminator::operator=(AssaultTerminator& marine)
{
	return (marine);
}

//~--------------------------------------------------------~
// Functions

ISpaceMarine* AssaultTerminator::clone(void) const
{
	ISpaceMarine* marine = new AssaultTerminator();

	return (marine);
}

void	AssaultTerminator::battleCry(void) const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;

	return;
}

void	AssaultTerminator::rangedAttack(void) const
{
	std::cout << "* does nothing *" << std::endl;

	return;
}

void	AssaultTerminator::meleeAttack(void) const
{
	std::cout << "* attacks with chainfists *" << std::endl;

	return;
}
