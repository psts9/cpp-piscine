#include <string>
#include <iostream>
#include <ctype.h>

static const int g_symbolCount = 7;

const std::string g_symbolTable[] =
{
	"(",
	")",
	"+",
	"-",
	"/",
	"*",
};

bool	isValidSymbol(std::string const& symbol)
{
	for (int i = 0; i < g_symbolCount; ++i)
	{
		if (g_symbolTable[i] == symbol)
			return (true);
	}
	return (false);
}

bool	isNumber(std::string const& str)
{
	bool	hasDot = false;

	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
		{
			if (!hasDot)
				hasDot = true;
			else
				return (false);
		}
	}
	return (true);
}
