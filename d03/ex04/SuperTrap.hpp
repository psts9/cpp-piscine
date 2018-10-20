#ifndef SUPERTRAP_H
# define SUPERTRAP_H

# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{
public:
	SuperTrap(void);
	SuperTrap(std::string const& name);
	SuperTrap(SuperTrap const& superTrap);
	~SuperTrap(void);

	using FragTrap::rangedAttack;
	using NinjaTrap::meleeAttack;

private:
	void	init(std::string const& name);

};

#endif
