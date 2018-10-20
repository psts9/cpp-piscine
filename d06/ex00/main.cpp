#include <sstream>
#include <iostream>
#include <cmath>
#include <limits>

int		strtoint(std::string const& str)
{
	std::stringstream ss;

	ss << str;

	int i;
	ss >> i;

	return (i);
}

bool	isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	isChar(std::string const& str)
{
	if (str.size() == 1 && isDigit(str[0]) == false)
			return (true);
	return (false);
}

bool	isPrintable(char c)
{
	if (c > 31)
		return (true);
	return (false);
}

char	strtochar(std::string const& str)
{
	int i = strtoint(str);

	return (static_cast<char>(i));
}

double	strtodbl(std::string const& str)
{
	std::stringstream ss;

	ss << str;

	double d;
	ss >> d;

	return (d);
}

float	strtoflt(std::string const& str)
{
	std::stringstream ss;

	std::string temp = str;

	temp[temp.size() - 1] = '\0';

	ss << temp;

	float f;
	ss >> f;

	return (f);
}

bool isInt(std::string const& str)
{
	size_t i = 0;

	if (str[i] == '+' || str[i] == '-')
		++i;
	for (; i < str.size(); ++i)
	{
		if (!isDigit(str[i]))
			return (false);
	}
	return (true);
}

bool isDouble(std::string const& str)
{
	size_t i = 0;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return (true);

	if (str[i] == '+' || str[i] == '-')
		++i;

	bool seenDot = false;

	for (; i < str.size(); ++i)
	{
		if (!isDigit(str[i]))
		{
			if (str[i] != '.')
				return (false);
			else
			{
				if (seenDot)
					return (false);
				seenDot = true;
			}
		}
	}

	return (true);
}

bool	isFloat(std::string const& str)
{
	size_t i = 0;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return (true);

	if (str[i] == '+' || str[i] == '-')
		++i;

	bool seenDot = false;

	for (; i < str.size(); ++i)
	{
		if (!isDigit(str[i]))
		{
			if (str[i] == 'f')
			{
				if (i == str.size() - 1)
					return (true);
			}
			if (str[i] != '.')
				return (false);
			else
			{
				if (seenDot)
					return (false);
				seenDot = true;
			}
		}
	}

	return (true);
}

void convToChar(std::string const& str)
{
	char c = str[0];

	if (isPrintable(c))
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convToInt(std::string const& str)
{
	int i = strtoint(str);

	if (i >= 128)
		std::cout << "char: impossible" << std::endl;
	else if (!isPrintable(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(i) << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void convToFloat(std::string const& str)
{
	float f = strtoflt(str);

	if (str == "-inff" || str == "+inff" || str == "nanf" || f >= 128)
		std::cout << "char: impossible" << std::endl;
	else if (!isPrintable(f))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(f) << std::endl;
	if (str == "-inff" || str == "+inff" || str == "nanf" || f > INT_MAX || f < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convToDouble(std::string const& str)
{
	double d = strtodbl(str);

	if (str == "-inf" || str == "+inf" || str == "nan" || d >= 128)
		std::cout << "char: impossible" << std::endl;
	else if (!isPrintable(d))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(d) << std::endl;
	if (str == "-inf" || str == "+inf" || str == "nan" || d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

int main(int argc, char **argv)
{
	int type = 0;

	if (argc == 1)
	{
		std::cout << "Usage: " << argv[0] << " number/char" << std::endl;
		return (1);
	}
	if (argc > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return (1);
	}

	if (isChar(argv[1]))
		type = 1;
	else if (isInt(argv[1]))
		type = 2;
	else if (isDouble(argv[1]))
		type = 3;
	else if (isFloat(argv[1]))
		type = 4;

	if (type == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (0);
	}

	if (type == 1)
	{
		std::cout << "--char--" << std::endl;
		convToChar(argv[1]);
	}
	else if (type == 2)
	{
		std::cout << "--int--" << std::endl;
		convToInt(argv[1]);
	}
	else if (type == 3)
	{
		std::cout << "--double--" << std::endl;
		convToDouble(argv[1]);
	}
	else if (type == 4)
	{
		std::cout << "--float--" << std::endl;
		convToFloat(argv[1]);
	}

	return (0);
}
