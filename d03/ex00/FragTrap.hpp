#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <string>

class FragTrap
{
public:
	FragTrap(void);
	FragTrap(std::string const& name);
	FragTrap(FragTrap const& fragTrap);
	~FragTrap(void);

	FragTrap& operator=(FragTrap const& rhs);

	void	rangedAttack(std::string const& target) const;
	void	meleeAttack(std::string const& target) const;
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const& target);

	std::string		getName(void) const;
	unsigned int	getLevel(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getMaxHitPoints(void) const;
	unsigned int	getMaxEnergyPoints(void) const;
	unsigned int	getMeleeAttackDamage(void) const;
	unsigned int	getRangedAttackDamage(void) const;
	unsigned int	getArmorDamageReduction(void) const;

private:
	void init(void);

	std::string		name_;

	unsigned int	level_;

	unsigned int	hitPoints_;
	unsigned int	energyPoints_;

	unsigned int	maxHitPoints_;
	unsigned int	maxEnergyPoints_;

	unsigned int	meleeAttackDamage_;
	unsigned int	rangedAttackDamage_;
	
	unsigned int	armorDamageReduction_;

};

#endif
