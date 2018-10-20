#include <cstdlib>

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Character::Character(void) : name_("default"), matCount_(0)
{
	this->materia_ = new AMateria*[4];

	return;
}

Character::Character(std::string const& name) : name_(name), matCount_(0)
{
	this->materia_ = new AMateria*[4];

	return;
}

Character::Character(Character const& character)
{
	this->materia_ = new AMateria*[4];

	*this = character;

	return;
}

Character::~Character(void)
{
	delete [] this->materia_;

	return;
}

//~--------------------------------------------------------~
// Get

std::string const& Character::getName(void) const
{
	return (this->name_);
}

AMateria*	Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= this->matCount_)
		return (NULL);

	return (this->materia_[idx]);
}

unsigned short Character::getMatCount(void) const
{
	return (this->matCount_);
}

//~--------------------------------------------------------~
// Operators

Character& Character::operator=(Character const& character)
{
	this->name_		= character.getName();
	this->matCount_	= character.getMatCount();

	delete [] this->materia_;

	for (int i = 0; i < this->matCount_; ++i)
		this->materia_[i] = character.getMateria(i);

	return (*this);
}

//~--------------------------------------------------------~
// Functions

void	Character::equip(AMateria* m)
{
	if (this->matCount_ >= 4)
		return;

	this->materia_[this->matCount_] = m;
	++this->matCount_;

	return;
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return;

	if (idx > this->matCount_ - 1)
		return;

	this->materia_[idx] = NULL;

	for (int i = idx; i < this->matCount_ - 1; ++i)
		this->materia_[i] = this->materia_[i + 1];

	--this->matCount_;

	return;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > this->matCount_ - 1 || idx < 0)
		return;

	this->materia_[idx]->use(target);

	return;
}
