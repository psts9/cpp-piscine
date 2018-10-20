#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(MateriaSource const& materiaSource);
	~MateriaSource(void);

	MateriaSource& operator=(MateriaSource const& materiaSource);

	unsigned short getMatCount(void) const;
	AMateria*	   getMateria(int idx) const;

	void		learnMateria(AMateria* materia);
	AMateria*	createMateria(std::string const& type);

private:
	AMateria** materia_;
	unsigned short matCount_;
};

#endif
