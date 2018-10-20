#include <iostream>

#include "RadScorpion.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

RadScorpion::RadScorpion(void) :
	Enemy(80, "Rad Scorpion")
{
	std::cout << "* click click click *" << std::endl;

	return;
}

RadScorpion::RadScorpion(int hp, std::string const& type) :
	Enemy(hp, type)
{
	std::cout << "* click click click *" << std::endl;

	return;
}

RadScorpion::RadScorpion(RadScorpion const& radScorpion) :
	Enemy(radScorpion.getHP(), radScorpion.getType())
{
	std::cout << "* click click click *" << std::endl;

	return;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;

	return;
}

//~--------------------------------------------------------~
// Functions
