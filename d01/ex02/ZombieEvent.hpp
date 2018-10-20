#ifndef ZOMBIE_EVENT_H
# define ZOMBIE_EVENT_H

# include "Zombie.hpp"

class ZombieEvent
{
public:
	ZombieEvent(void);
	ZombieEvent(std::string zombieType);
	~ZombieEvent(void);

	Zombie* newZombie(std::string name);

	void	randomChump(void) const;
	void	setZombieType(std::string type);

private:
	std::string	zombieType_;
};

#endif
