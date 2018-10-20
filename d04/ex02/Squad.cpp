#include <cstdlib>
#include <iostream>

#include "Squad.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Squad::Squad(void) : squad_(NULL), unitCount_(0)
{
	this->squad_ = new ISpaceMarine* [512];

	return;
}

Squad::Squad(Squad const& squad)
{
	this->squad_ = new ISpaceMarine* [512];

	*this = squad;

	return;
}

Squad::~Squad(void)
{
	for (int i = 0; i < this->unitCount_; ++i)
		delete (this->squad_[i]);

	return;
}

//~--------------------------------------------------------~
// Get

int				Squad::getCount(void) const
{
	return (this->unitCount_);
}

ISpaceMarine*	Squad::getUnit(int unitIndex) const
{
	if (unitIndex >= this->unitCount_ || unitIndex < 0)
		return (NULL);

	return (this->squad_[unitIndex]);
}

//~--------------------------------------------------------~
// Operators

Squad& Squad::operator=(Squad const& squad)
{
	if (this->unitCount_ > 0)
		Squad::~Squad();

	this->unitCount_ = 0;

	for (int i = 0; i < squad.getCount(); ++i)
	{
		std::cout << i << std::endl;
		this->push(squad.getUnit(i)->clone());
	}

	this->unitCount_ = squad.getCount();

	return (*this);
}

//~--------------------------------------------------------~
// Functions

int	Squad::push(ISpaceMarine* marine)
{
	if (marine == NULL)
	{
		std::cerr << "Marine being pushed is NULL" << std::endl;

		return (this->unitCount_);
	}

	for (int i = 0; i < this->unitCount_; ++i)
	{
		if (this->squad_[i] == marine)
		{
			std::cerr << "Unit already in squad!" << std::endl;

			return (this->unitCount_);
		}
	}

	this->squad_[this->unitCount_] = marine;
	++this->unitCount_;

	return (this->unitCount_);
}
