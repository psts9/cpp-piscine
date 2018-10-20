#ifndef ClapTrap_H
# define ClapTrap_H

# include <string>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string const& name);
	ClapTrap(ClapTrap const& clapTrap);
	~ClapTrap(void);

	ClapTrap& operator=(ClapTrap const& rhs);

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string		getName(void) const;
	unsigned int	getLevel(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getMaxHitPoints(void) const;
	unsigned int	getMaxEnergyPoints(void) const;
	unsigned int	getMeleeAttackDamage(void) const;
	unsigned int	getRangedAttackDamage(void) const;
	unsigned int	getArmorDamageReduction(void) const;

protected:
	std::string		name_;

	unsigned int	level_;

	unsigned int	hitPoints_;
	unsigned int	energyPoints_;

	unsigned int	maxHitPoints_;
	unsigned int	maxEnergyPoints_;

	unsigned int	meleeAttackDamage_;
	unsigned int	rangedAttackDamage_;
	
	unsigned int	armorDamageReduction_;

private:
	void init(void);
};

#endif
