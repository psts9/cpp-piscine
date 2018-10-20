#include <iostream>

#include <cstdlib>
#include <unistd.h>
#include <curses.h>

#include "HostnameModule.hpp"
#include "OSInfoModule.hpp"
#include "DatetimeModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"
#include "TextDisplay.hpp"
#include "GraphicalDisplay.hpp"

bool	isAddingModule(char c)
{
	static std::string const modules = "hodcrn";

	for (size_t i = 0; i < modules.size(); ++i)
	{
		if (modules[i] == c)
			return (true);
	}
	return (false);
}

IMonitorModule* addModule(char c)
{
	IMonitorModule* m = NULL;

	switch (c)
	{
	case 'h': m = new HostnameModule;	break;
	case 'o': m = new OSInfoModule;		break;
	case 'd': m = new DatetimeModule;	break;
	case 'c': m = new CPUModule;		break;
	case 'r': m = new RAMModule;		break;
	case 'n': m = new NetworkModule;	break;
	}

	return (m);
}

int main(int argc, char **argv)
{
	bool graphicalMode = false;

	if (argc > 1)
	{
		if (strncmp(argv[1], "-g", 2) == 0)
			graphicalMode = true;
	}

	std::vector<IMonitorModule*> modules;

	modules.push_back(new HostnameModule);
	modules.push_back(new OSInfoModule);
	modules.push_back(new DatetimeModule);
	modules.push_back(new CPUModule);
	modules.push_back(new RAMModule);
	modules.push_back(new NetworkModule);

	IMonitorDisplay* d;

	if (!graphicalMode)
		d = new TextDisplay;
	else
		d = new GraphicalDisplay;

	int c;
	int	ticks = 20;

	if (!graphicalMode)
	{
		while (1)
		{	
			if (ticks == 20)
			{
				ticks = 0;
				d->display(modules);
			}
			usleep(50000);
			c = getch();
			c = tolower(c);
			if (c == 'q')
				break;
			if (c == 'z')
			{
				if (modules.size() > 0)
					modules.erase(modules.begin());
				d->display(modules);
			}
			if (c == 'x')
			{
				if (modules.size() > 0)
					modules.pop_back();
				d->display(modules);
			}
			if (isAddingModule(c))
			{
				modules.push_back(addModule(c));
				d->display(modules);
			}
			++ticks;
		}
	}
	else
	{
		d->display(modules);
	}
	delete d;

	return (0);
}
