#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Pony.hpp"

void	ponyOnTheStack(std::string description)
{
	Pony horse = Pony((rand() % 99 + 1), (rand() % 2 + 4), description + " horse");

	horse.neigh();
	std::cout << std::endl;

	return;
}

void	ponyOnTheHeap(std::string description)
{
	Pony *horse = new Pony((rand() % 99 + 1), (rand() % 2 + 4), description + " horse");

	horse->neigh();
	std::cout << std::endl;

	delete horse;
	return;
}

int		main(void)
{
	srand(time(NULL));

	ponyOnTheStack("good");
	ponyOnTheHeap("bad");
	
	return (0);
}
