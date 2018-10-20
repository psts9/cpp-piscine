#include <iostream>

#include "ZombieEvent.hpp"

int main(void)
{
	ZombieEvent zombieEvent;

	srand(time(NULL));

	zombieEvent.setZombieType("Walker");

	Zombie *zombie1 = zombieEvent.newZombie("Guy");
	Zombie *zombie2 = zombieEvent.newZombie("Zombie");
	zombieEvent.randomChump();
	zombieEvent.randomChump();
	zombie1->announce();
	zombie2->announce();

	std::cout << "//////////////////////////" << std::endl;

	zombieEvent.setZombieType("Clicker");

	Zombie *zombie3 = zombieEvent.newZombie("Dude");
	Zombie *zombie4 = zombieEvent.newZombie("Zombie2");
	zombieEvent.randomChump();
	zombieEvent.randomChump();
	zombie3->announce();
	zombie4->announce();

	delete zombie1;
	delete zombie2;
	delete zombie3;
	delete zombie4;

	return (0);
}
