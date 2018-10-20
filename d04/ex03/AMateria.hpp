#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>

# include "ICharacter.hpp"

class AMateria
{
public:
	AMateria(std::string const& type);
	AMateria(AMateria const& materia);
	virtual ~AMateria(void);

	AMateria& operator=(AMateria const& materia);

	std::string const& getType(void) const;
	unsigned int getXP(void) const;

	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);

private:
	AMateria(void);

	std::string type_;
	unsigned int xp_;

};

#endif
