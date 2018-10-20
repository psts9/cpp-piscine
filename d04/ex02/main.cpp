#include <iostream>

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"


int main(void)
{
	TacticalMarine* mike = new TacticalMarine();
	mike->battleCry();
	delete mike;

	std::cout << std::endl;

	AssaultTerminator* kevin = new AssaultTerminator();
	kevin->battleCry();
	ISpaceMarine* guy = kevin->clone();
	delete kevin;

	guy->battleCry();

	std::cout << std::endl;

	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << std::endl;

	Squad squad;

	ISpaceMarine* you = new TacticalMarine;
	ISpaceMarine* me = new AssaultTerminator;

	squad.push(you);
	squad.push(you);
	squad.push(me);
	for (int i = 0; i < squad.getCount() + 3; ++i)
	{
		if (ISpaceMarine* cur = squad.getUnit(i))
		{
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
	}

	Squad squad2 = squad;

	for (int i = 0; i < squad2.getCount() + 3; ++i)
	{
		if (ISpaceMarine* cur = squad2.getUnit(i))
		{
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
		}
	}

	Squad squad3;

	ISpaceMarine* temp = new TacticalMarine;

	squad3.push(temp);

	std::cout << "Deleting" << std::endl << std::endl;

	squad3 = squad2;

	std::cout << std::endl;

	std::cout << std::endl;

	delete vlc;

	return (0);
}
