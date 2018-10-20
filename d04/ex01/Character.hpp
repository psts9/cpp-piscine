#ifndef CHARACTER_H
# define CHARACTER_H

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
	Character(std::string const& name);
	Character(Character const& character);
	~Character(void);

	Character& operator=(Character const& character);

	std::string	const& getName(void) const;
	AWeapon*		   getWeapon(void) const;
	int				   getAP(void) const;

	void	recoverAP(void);
	void	equip(AWeapon* weapon);
	void	attack(Enemy* enemy);

private:
	Character(void);

	AWeapon*	weapon_;
	std::string	name_;
	int	ap_;
};

std::ostream& operator<<(std::ostream& o, Character const& character);

#endif
