#include <iostream>

#include "Sorcerer.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Sorcerer::Sorcerer(void)
{
	this->name_  = "default";
	this->title_ = "default";

	return;
}

Sorcerer::Sorcerer(std::string const& name, std::string const& title)
{
	this->name_	 = name;
	this->title_ = title;

	std::cout << name << ", " << title << ", is born !" << std::endl;

	return;
}

Sorcerer::Sorcerer(Sorcerer const& sorcerer)
{
	*this = sorcerer;

	std::cout << this->name_ << ", " << this->title_ << ", is born !" << std::endl;

	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout   <<
	this->name_ << ", " << this->title_ << ", "	 	 <<
	"is dead. Consequences will never be the same !" <<
	std::endl;

	return;
}

//~--------------------------------------------------------~
// Get

std::string	Sorcerer::getName(void) const
{
	return (this->name_);
}

std::string Sorcerer::getTitle(void) const
{
	return (this->title_);
}

//~--------------------------------------------------------~
// Operators

Sorcerer& Sorcerer::operator=(Sorcerer const& sorcerer)
{
	this->name_  = sorcerer.getName();
	this->title_ = sorcerer.getTitle();

	return (*this);
}

std::ostream& operator<<(std::ostream& o, Sorcerer const& sorcerer)
{
	o << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << " and I like ponies !" << std::endl;

	return (o);
}

//~--------------------------------------------------------~
// Functions

void	Sorcerer::polymorph(Victim const& victim) const
{
	victim.getPolyMorphed();

	return;
}
