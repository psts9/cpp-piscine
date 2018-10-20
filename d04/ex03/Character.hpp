#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(std::string const& name);
	Character(Character const& character);
	~Character(void);

	Character& operator=(Character const& character);

	std::string const& getName(void) const;
	AMateria*		   getMateria(int idx) const;
	unsigned short	   getMatCount(void) const;

	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);

private:
	Character(void);

	std::string name_;
	AMateria **materia_;
	unsigned short matCount_;
};

#endif
