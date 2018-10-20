#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(std::string const& name);
	NinjaTrap(NinjaTrap const& ninjaTrap);
	~NinjaTrap(void);

	void	rangedAttack(std::string const& target) const;
	void	meleeAttack(std::string const& target) const;
	void	ninjaShoebox(ClapTrap const& clapTrap);
	void	ninjaShoebox(FragTrap const& fragTrap);
	void	ninjaShoebox(NinjaTrap const& ninjaTrap);
	void	ninjaShoebox(ScavTrap const& scavTrap);

private:
	void	init(std::string const& name);

};

#endif
