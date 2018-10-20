#include "AMateria.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

AMateria::AMateria(void) : type_("default"), xp_(0)
{
	return;
}

AMateria::AMateria(std::string const& type) : type_(type), xp_(0)
{
	return;
}

AMateria::AMateria(AMateria const& materia) : type_("default")
{
	*this = materia;

	return;
}

AMateria::~AMateria(void)
{
	return;
}

//~--------------------------------------------------------~
// Get

std::string const& AMateria::getType(void) const
{
	return (this->type_);
}

unsigned int	   AMateria::getXP(void) const
{
	return (this->xp_);
}

//~--------------------------------------------------------~
// Operators

AMateria& AMateria::operator=(AMateria const& materia)
{
	this->xp_ = materia.getXP();

	return (*this);
}

//~--------------------------------------------------------~
// Functions

void	AMateria::use(ICharacter& target)
{
	this->xp_ += 10;

	target.getName();

	return;
}
