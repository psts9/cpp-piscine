#include <iostream>
#include <curses.h>

#include "TextDisplay.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

TextDisplay::TextDisplay(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);
	nodelay(stdscr, true);
}

TextDisplay::~TextDisplay(void)
{
	endwin();
}

//~--------------------------------------------------------~
// Functions

void	TextDisplay::display(std::vector<IMonitorModule*> const& m) const
{
	int line = 0;

	wrefresh(stdscr);
	clear();
	for (size_t j = 0; j < m.size(); ++j)
	{
		mvwaddstr(stdscr, line++, 0, m[j]->getName().c_str());
		
		std::vector<std::string> fieldNames = m[j]->getFieldNames();
		std::vector<std::string> fieldInfo = m[j]->getFieldInfo();

		for (size_t i = 0; i < fieldNames.size(); ++i)
		{
			std::string curr = fieldNames[i] + ": " + fieldInfo[i];
			mvwaddstr(stdscr, line++, 0, curr.c_str());
		}

		++line;
	}
}
