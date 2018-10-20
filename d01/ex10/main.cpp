#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void	getStdin(void)
{
	std::string line;

	while (1)
	{
		std::getline(std::cin, line);
		if (!std::cin)
			return;
		std::cout << line << std::endl;
	}
}

bool	validFile(std::string const& fileName)
{
	struct stat	statBuf;

	int res = stat(fileName.c_str(), &statBuf);
	
	if (res == -1)
		return (false);
	else if (S_ISDIR(statBuf.st_mode))
	{
		errno = EISDIR;
		return (false);
	}

	return (true);
}

bool	printContentsOfFile(std::string const& fileName)
{
	std::string		line;
	std::ifstream	inStream(fileName);

	if (!inStream)
		return (false);

	if (!validFile(fileName))
		return (false);

	while (std::getline(inStream, line))
		std::cout << line << std::endl;

	return (true);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		getStdin();
		return (0);
	}
	
	for (int i = 1; i < argc; ++i)
	{
		if (!printContentsOfFile(argv[i]))
			std::cerr << "cat: " << argv[i] << ": " << std::strerror(errno) << std::endl;
	}

	return (0);
}
