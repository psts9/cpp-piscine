#include "Enemy.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Enemy::Enemy(void) :
	type_("default"), hp_(0)
{
	return;
}

Enemy::Enemy(int hp, std::string const& type) :
	type_(type), hp_(hp)
{
	return;
}

Enemy::Enemy(Enemy const& enemy) :
	type_(enemy.getType()), hp_(enemy.getHP())
{
	return;
}

Enemy::~Enemy(void)
{
	return;
}

//~--------------------------------------------------------~
// Get

std::string const& Enemy::getType(void) const
{
	return (this->type_);
}

int	Enemy::getHP(void) const
{
	return (this->hp_);
}

//~--------------------------------------------------------~
// Operators

Enemy& Enemy::operator=(Enemy const& enemy)
{
	this->type_ = enemy.getType();
	this->hp_	= enemy.getHP();

	return (*this);
}

//~--------------------------------------------------------~
// Functions

void	Enemy::takeDamage(int amount)
{
	if (amount < 0)
		return;

	this->hp_ -= amount;

	return;
}
