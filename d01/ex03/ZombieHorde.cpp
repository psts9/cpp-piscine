#include "ZombieHorde.hpp"

std::string	randName(void)
{
	std::string name(rand() % 8 + 3, 'a');

	for (int i = 0; i < (int)name.size(); ++i)
		name[i] += (rand() % 26);

	name[0] = toupper(name[0]);

	return (name);
}

ZombieHorde::ZombieHorde(int zombieCount) : zombieCount_(zombieCount)
{
	this->zombieHorde_ = new Zombie[this->zombieCount_];

	for (int i = 0; i < this->zombieCount_; ++i)
	{
		this->zombieHorde_[i].setName(randName());
		this->zombieHorde_[i].setType("Walker");
	}

	return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] this->zombieHorde_;

	return;
}

void	ZombieHorde::announce(void) const
{
	for (int i = 0; i < this->zombieCount_; ++i)
		this->zombieHorde_[i].announce();
	
	return;
}
