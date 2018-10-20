#ifndef ZOMBIEHORDE_H
# define ZOMBIEHORDE_H

# include "Zombie.hpp"

class ZombieHorde
{
public:
	ZombieHorde(int zombieCount);
	~ZombieHorde(void);

	void	announce(void) const;

private:
	Zombie*	zombieHorde_;
	int		zombieCount_;
};

#endif
