#include <iostream>

#include "Peon.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Peon::Peon(void) : Victim("default")
{
	this->name_ = "default";

	return;
}

Peon::Peon(std::string const& name) : Victim(name)
{
	this->name_ = name;

	std::cout << "Zog zog." << std::endl;

	return;
}

Peon::Peon(Peon const& peon) : Victim("default")
{
	*this = peon;

	std::cout << "Zog zog." << std::endl;

	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;

	return;
}

//~--------------------------------------------------------~
// Functions

void	Peon::getPolyMorphed(void) const
{
	std::cout << this->name_ << " has been turned into a pink pony !" << std::endl;

	return;
}
