#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) : zombieType_("default")
{
	return;
}

ZombieEvent::ZombieEvent(std::string zombieType) : zombieType_(zombieType)
{
	return;
}

ZombieEvent::~ZombieEvent(void)
{
	return;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie* zombie = new Zombie(name, this->zombieType_);

	return (zombie);
}

void	ZombieEvent::randomChump(void) const
{
	std::string randName(rand() % 8 + 3, 'a');

	for (int i = 0; i < (int)randName.size(); ++i)
		randName[i] += (rand() % 26);

	randName[0] = toupper(randName[0]);

	Zombie zombie = Zombie(randName, this->zombieType_);
	zombie.announce();

	return;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->zombieType_ = type;

	return;
}
