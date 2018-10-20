#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>

std::string	toString(char c)
{
	return (std::string(1, c));
}

std::string	getNumber(std::string const& str, size_t &i)
{
	std::string number;

	while (isdigit(str[i]) || str[i] == '.')
	{
		number += str[i];
		++i;
	}
	--i;

	return (number);
}

std::string	seperateArguments(std::string const& expr)
{
	std::string	resultString;

	for (size_t i = 0; i < expr.size(); ++i)
	{
		if (expr[i] != ' ')
		{
			if (isdigit(expr[i]))
				resultString += getNumber(expr, i) + ' ';
			else if (expr[i] != ' ')
			{
				resultString += expr[i];
				resultString += ' ';
			}
		}
	}
	resultString.pop_back();
	resultString.insert(0, "( ");
	resultString.append(" )");

	return (resultString);
}

int	tokenCount(std::string const& equStr)
{
	bool	prevSpace = true;
	int		result = 0;

	for (size_t i = 0; i < equStr.size(); ++i)
	{
		if (equStr[i] != ' ')
		{
			if (prevSpace)
			{
				++result;
				prevSpace = false;
			}
		}
		else
			prevSpace = true;
	}

	return (result);
}

std::string*	tokenize(std::string const& equStr, int& tokenAmount, bool parse)
{
	std::string parsedExpr;

	if (parse)
		parsedExpr = seperateArguments(equStr);
	else
		parsedExpr = equStr;

	char*	temp = new char[parsedExpr.size() + 1];

	std::copy(parsedExpr.begin(), parsedExpr.end(), temp);
	temp[parsedExpr.size()] = '\0';

	int tokenC = tokenCount(parsedExpr);

	std::string*	tokens = new std::string[tokenC];
	char*		 	tokenPtr = strtok(temp, " ");


	int i = 0;
	while (tokenPtr != NULL)
	{
		tokens[i] = tokenPtr;
		tokenPtr = strtok(NULL, " ");
		++i;
	}

	tokenAmount = tokenC;

	delete [] temp;

	return (tokens);
}
