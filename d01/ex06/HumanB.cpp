#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack(void) const
{
	std::cout   << 
	this->name_ << " attacks with his " <<
	this->weapon_->getType()			<<
	std::endl;

	return;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon_ = &weapon;

	return;
}
