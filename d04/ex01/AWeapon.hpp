#ifndef AWEAPON_H
# define AWEAPON_H

# include <string>

class AWeapon
{
public:
	AWeapon(std::string const& name, int apcost, int damage);
	AWeapon(AWeapon const& weapon);
	virtual ~AWeapon(void);

	AWeapon& operator=(AWeapon const& weapon);

	std::string const&  getName(void) const;
	int					getAPCost(void) const;
	int					getDamage(void) const;

	virtual void attack(void) const = 0;

private:
	AWeapon(void);

	std::string name_;
	int	apcost_;
	int damage_;
};

#endif
