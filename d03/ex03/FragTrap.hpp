#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string const& name);
	FragTrap(FragTrap const& fragTrap);
	~FragTrap(void);

	void	rangedAttack(std::string const& target) const;
	void	meleeAttack(std::string const& target) const;
	void	vaulthunter_dot_exe(std::string const& target);

private:
	void	init(void);

};

#endif
