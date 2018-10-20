#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string const& name);
	ScavTrap(ScavTrap const& scavTrap);
	~ScavTrap(void);

	void	rangedAttack(std::string const& target) const;
	void	meleeAttack(std::string const& target) const;
	void	challengeNewcomer(std::string const& target);

private:
	void	init(void);

};

#endif
