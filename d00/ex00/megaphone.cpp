#include <iostream>
#include <ctype.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j]; ++j)
			putchar(toupper(argv[i][j]));
	}
	putchar('\n');
	return (0);
}
