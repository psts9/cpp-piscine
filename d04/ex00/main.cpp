#include <iostream>

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int	main(void)
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

//	victim.getPolyMorphed();
//	sorcerer.polymorph(victim);

	std::cout << std::endl;

	Peon* jonkanon = new Peon("jonkanon");
	Victim* ron = new Peon("Ron");

	ron->getPolyMorphed();
	jonkanon->getPolyMorphed();

	delete ron;
	delete jonkanon;

	std::cout << std::endl;

	return (0);
}
