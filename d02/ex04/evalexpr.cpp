#include <ctype.h>
#include <iostream>

#include "Fixed.hpp"
#include "tokenizer.hpp"
#include "validCheck.hpp"
#include "equationSolver.hpp"

void	evalexpr(std::string const& expr)
{
	Fixed result;

	int tokenAmount;

	std::string* tokens = tokenize(expr, tokenAmount, true);

	result = solveEquation(tokens, tokenAmount);

	std::cout << result << std::endl;

	delete [] tokens;

	return;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Usage: " << argv[0] << " equation" << std::endl;
		return (1);
	}
	else if (argc > 2)
	{
		std::cout << "Too many arguments" << std::endl;
		return (1);
	}

	evalexpr(argv[1]);

	return (0);
}
