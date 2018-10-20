#include "Fixed.hpp"
#include "validCheck.hpp"
#include "tokenizer.hpp"

#include <string>

void	printErrorAndExit(std::string const& errMsg)
{
	std::cout << errMsg << std::endl;

	exit(1);

	return;
}

int	getPrecedence(std::string s)
{
	if (s == "+" || s == "-")
		return (0);
	else
		return (2);
}

Fixed	solveRpn(std::string const& rpnStr)
{

	Fixed result;

	int tokenAmount;

	std::string* tokens = tokenize(rpnStr, tokenAmount, false);

	Fixed* numberStack = new Fixed[500];
	int	stackIndex = 0;

	for (int i = 0; i < tokenAmount; ++i)
	{
		if (tokens[i] == "+" || tokens[i] == "-" ||
			tokens[i] == "*" || tokens[i] == "/")
		{
			if (tokens[i] == "+")
			{
				result = numberStack[stackIndex];
				--stackIndex;
				if (stackIndex == 0)
					printErrorAndExit("Error");
				result = result + numberStack[stackIndex];
				--stackIndex;
				numberStack[++stackIndex] = result;
			}
			if (tokens[i] == "-")
			{
				result = numberStack[stackIndex];
				--stackIndex;
				if (stackIndex == 0)
					printErrorAndExit("Error");
				result = numberStack[stackIndex] - result;
				--stackIndex;
				numberStack[++stackIndex] = result;
			}
			if (tokens[i] == "/")
			{
				result = numberStack[stackIndex];
				--stackIndex;
				if (stackIndex == 0)
					printErrorAndExit("Error");
				result = numberStack[stackIndex] / result;
				--stackIndex;
				numberStack[++stackIndex] = result;
			}
			if (tokens[i] == "*")
			{
				result = numberStack[stackIndex];
				--stackIndex;
				if (stackIndex == 0)
					printErrorAndExit("Error");
				result = result * numberStack[stackIndex];
				--stackIndex;
				numberStack[++stackIndex] = result;
			}
		}
		else
			numberStack[++stackIndex] = std::stof(tokens[i]);
	}

	result = numberStack[stackIndex];

	--stackIndex;

	if (stackIndex != 0)
		printErrorAndExit("Error");

	delete [] tokens;

	return (result);
}

Fixed	solveEquation(std::string*& tokens, int& tokenAmount)
{

	Fixed result;

	std::string	rpnStr;
	std::string* operatorStack = new std::string[500];

	int	stackIndex = 0;

	for (int i = 0; i < tokenAmount; ++i)
	{
		if (isNumber(tokens[i]))
			rpnStr += tokens[i] + ' ';
		else if (tokens[i] == "+" || tokens[i] == "-" ||
			tokens[i] == "*" || tokens[i] == "/")
		{
			int precedence = getPrecedence(tokens[i]);
			while (getPrecedence(operatorStack[stackIndex]) > precedence)
			{
				if (operatorStack[stackIndex] == "(")
					break;
				rpnStr += operatorStack[stackIndex] + ' ';
				if (stackIndex == 0)
					printErrorAndExit("Error");
				--stackIndex;;
			}
			operatorStack[++stackIndex] = tokens[i];
		}
		else if (tokens[i] == "(")
		{
			operatorStack[++stackIndex] = tokens[i];
		}
		else if (tokens[i] == ")")
		{
			while (operatorStack[stackIndex] != "(")
			{
				if (stackIndex == 0)
					printErrorAndExit("Error");
				rpnStr += operatorStack[stackIndex] + ' ';
				--stackIndex;
			}
			if (stackIndex == 0)
				printErrorAndExit("Error");
			--stackIndex;
		}
		else if (tokens[i] != " ")
			printErrorAndExit("Error");
	}

	if (rpnStr.size() == 0)
		printErrorAndExit("Error");

	result = solveRpn(rpnStr);


	delete [] operatorStack;

	return (result);
}
