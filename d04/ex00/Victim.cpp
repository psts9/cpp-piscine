#include <iostream>

#include "Victim.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Victim::Victim(void)
{
	this->name_ = "default";

	return;
}

Victim::Victim(std::string const& name)
{
	this->name_ = name;

	std::cout << "Some random victim called " << name << " just popped !" << std::endl;

	return;
}

Victim::Victim(Victim const& victim)
{
	*this = victim;

	std::cout << "Some random victim called " << this->name_ << " just popped !" << std::endl;

	return;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << this->name_ << " just died for no apparent reason !" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Get

std::string Victim::getName(void) const
{
	return (this->name_);
}

//~--------------------------------------------------------~
// Operators

Victim& Victim::operator=(Victim const& victim)
{
	this->name_ = victim.getName();

	return (*this);
}

std::ostream& operator<<(std::ostream& o, Victim const& victim)
{
	o << "I'm " << victim.getName() << " and I like otters !" << std::endl;

	return (o);
}

//~--------------------------------------------------------~
// Functions

void	Victim::getPolyMorphed(void) const
{
	std::cout << this->name_ << " has been turned into a cute little sheep !" << std::endl;

	return;
}
