#include "AWeapon.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

AWeapon::AWeapon(void) :
	name_("default"), apcost_(0), damage_(0)
{
	return;
}

AWeapon::AWeapon(std::string const& name, int apcost, int damage) :
	name_(name), apcost_(apcost), damage_(damage)
{
	return;
}

AWeapon::AWeapon(AWeapon const& weapon)
{
	*this = weapon;

	return;
}

AWeapon::~AWeapon(void)
{
	return;
}

//~--------------------------------------------------------~
// Get

std::string const& AWeapon::getName(void) const
{
	return (this->name_);
}

int	AWeapon::getAPCost(void) const
{
	return (this->apcost_);
}

int	AWeapon::getDamage(void) const
{
	return (this->damage_);
}

//~--------------------------------------------------------~
// Operators

AWeapon& AWeapon::operator=(AWeapon const& weapon)
{
	this->name_   = weapon.getName();
	this->apcost_ = weapon.getAPCost();
	this->damage_ = weapon.getDamage();

	return (*this);
}
