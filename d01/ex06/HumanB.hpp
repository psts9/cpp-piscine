#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB(void);

	void	attack(void) const;

	void	setWeapon(Weapon& weapon);

private:
	const std::string	name_;
	Weapon*				weapon_;
};

#endif
