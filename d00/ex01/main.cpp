
#include <iostream>
#include "phonebook.hpp"

int main(void)
{
	std::string		command;
	pb::phonebook	phonebook;
	bool			running = true;

	std::cout << "WELCOME TO PHONEBOOK. COMMANDS: ADD, SEARCH, EXIT" << std::endl;
	while (running)
	{
		std::cin >> command;
		if (command == "ADD")
			phonebook.add();
		else if	(command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			running = false;
		else
			std::cout << "INVALID COMMAND: " << command << std::endl;
	}
	return (0);
}
