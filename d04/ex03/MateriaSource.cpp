#include <cstdlib>

#include "MateriaSource.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

MateriaSource::MateriaSource(void) : matCount_(0)
{
	this->materia_ = new AMateria*[4];

	return;
}

MateriaSource::MateriaSource(MateriaSource const& materiaSource)
{
	*this = materiaSource;

	return;
}

MateriaSource::~MateriaSource(void)
{
	delete [] this->materia_;

	return;
}

//~--------------------------------------------------------~
// Get

unsigned short	MateriaSource::getMatCount(void) const
{
	return (this->matCount_);
}

AMateria*		MateriaSource::getMateria(int idx) const
{
	if (idx < 0 || idx >= this->matCount_)
		return (NULL);

	return (this->materia_[idx]);
}

//~--------------------------------------------------------~
// Operators

MateriaSource& MateriaSource::operator=(MateriaSource const& materiaSource)
{
	this->matCount_	= materiaSource.getMatCount();

	delete [] this->materia_;

	for (int i = 0; i < this->matCount_; ++i)
		this->materia_[i] = materiaSource.getMateria(i);

	return (*this);
}

//~--------------------------------------------------------~
// Functions

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (this->matCount_ >= 4)
		return;

	this->materia_[this->matCount_] = materia;
	++this->matCount_;

	return;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < this->matCount_; ++i)
	{
		if (this->materia_[i]->getType() == type)
			return (this->materia_[i]->clone());
	}

	return (NULL);
}
