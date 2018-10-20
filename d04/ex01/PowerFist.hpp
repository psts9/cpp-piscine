#ifndef POWERFIST_H
# define POWERFIST_H

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist(void);
	virtual ~PowerFist(void);

	virtual void attack(void) const;

private:
	PowerFist(std::string const& name, int apcost, int damage);
	PowerFist(PowerFist const& powerFist);
	
};

#endif
