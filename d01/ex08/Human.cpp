#include <iostream>

#include "Human.hpp"

void	Human::meleeAttack(std::string const& target)
{
	std::cout << "Attacking " << target << " using melee tactics" << std::endl;

	return;
}

void	Human::rangedAttack(std::string const& target)
{
	std::cout << "Attacking " << target << " using ranged tactics" << std::endl;

	return;
}

void	Human::intimidatingShout(std::string const& target)
{
	std::cout << "Shouting at " << target << " very intimidatingly" << std::endl;

	return;
}

void	Human::action(std::string const& actionName, std::string const& target)
{
	const static int	commandCount = 3;

	std::string	funcTab[commandCount] =
	{
		"melee",
		"ranged",
		"shout"
	};

	typedef void (Human::*Action)(std::string const& target);

	Action 	actionFuncTab[commandCount] =
	{
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	for (int i = 0; i < commandCount; ++i)
	{
		if (funcTab[i] == actionName)
		{
			(this->*(actionFuncTab[i]))(target);
			return;
		}
	}
	std::cout << "Invalid action!" << std::endl;
	return;
}
