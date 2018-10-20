#include <iostream>

#include "Character.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Character::Character(void) :
	weapon_(NULL), name_("default"), ap_(40)
{
	return;
}

Character::Character(std::string const& name) :
	weapon_(NULL), name_(name), ap_(40)
{
	return;
}

Character::Character(Character const& character)
{
	*this = character;

	return;
}

Character::~Character(void)
{
	return;
}

//~--------------------------------------------------------~
// Get

std::string const& Character::getName(void) const
{
	return (this->name_);
}

AWeapon*	Character::getWeapon(void) const
{
	return (this->weapon_);
}

int			Character::getAP(void) const
{
	return (this->ap_);
}

//~--------------------------------------------------------~
// Operators

Character& Character::operator=(Character const& character)
{
	this->weapon_ = character.getWeapon();
	this->name_	  = character.getName();
	this->ap_	  = character.getAP();

	return (*this);
}

std::ostream& operator<<(std::ostream& o, Character const& character)
{
	o << character.getName() << " has " << character.getAP() << " AP and ";

	if (character.getWeapon() != NULL)
		o << "wields a " << character.getWeapon()->getName();
	else
		o << "is unarmed";

	o << std::endl;

	return (o);
}

//~--------------------------------------------------------~
// Functions

void	Character::recoverAP(void)
{
	if (this->ap_ + 10 > 40)
		this->ap_ = 40;
	else
		this->ap_ += 10;

	return;
}

void	Character::equip(AWeapon* weapon)
{
	this->weapon_ = weapon;

	return;
}

void	Character::attack(Enemy* enemy)
{
	if (this->ap_ < this->getWeapon()->getAPCost())
	{
		std::cout << "Not enough AP to attack!" << std::endl;
		std::cout << "Currently have: " << this->ap_ << ". Need: " << this->getWeapon()->getAPCost() << std::endl;

		return;
	}

	this->ap_ -= this->getWeapon()->getAPCost();

	std::cout << this->name_ << " attacks " << enemy->getType() << " with a " << this->getWeapon()->getName() << std::endl;

	this->getWeapon()->attack();
	enemy->takeDamage(this->getWeapon()->getDamage());

	if (enemy->getHP() < 0)
		delete enemy;

	return;
}
