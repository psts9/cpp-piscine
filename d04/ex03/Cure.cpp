#include <iostream>

#include "Cure.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Cure::Cure(void) : AMateria("cure")
{
	return;
}

Cure::Cure(Cure const& cure) : AMateria("cure")
{
	*this = cure;

	return;
}

Cure::~Cure(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

	AMateria::use(target);

	return;
}

AMateria*	Cure::clone(void) const
{
	Cure* cure = new Cure();

	return (cure);
}
