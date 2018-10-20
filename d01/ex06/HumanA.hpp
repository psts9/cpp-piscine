#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void	attack(void) const;

private:
	const std::string	name_;
	Weapon&				weapon_;
};

#endif
