#ifndef PLASMARIFLE_H
# define PLASMARIFLE_H

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(void);
	virtual ~PlasmaRifle(void);

	virtual void attack(void) const;

private:
	PlasmaRifle(std::string const& name, int apcost, int damage);
	PlasmaRifle(PlasmaRifle const& plasmaRifle);

};

#endif
