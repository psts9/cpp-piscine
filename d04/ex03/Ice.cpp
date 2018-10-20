#include <iostream>

#include "Ice.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Ice::Ice(void) : AMateria("ice")
{
	return;
}

Ice::Ice(Ice const& ice) : AMateria("ice")
{
	*this = ice;

	return;
}

Ice::~Ice(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

	AMateria::use(target);

	return;
}

AMateria*	Ice::clone(void) const
{
	Ice* ice = new Ice();

	return (ice);
}
