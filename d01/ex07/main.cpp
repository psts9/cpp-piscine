#include <iostream>
#include <fstream>
#include <string>

void	replaceAllOccurrences(std::string& wordString, std::string const& oldStr,
							  std::string const& newStr)
{
	std::string::size_type n = 0;
	while ((n = wordString.find(oldStr, n)) != std::string::npos)
	{
		wordString.replace(n, oldStr.size(), newStr);
		n += newStr.size();
	}
}

bool	verifyFile(std::string file, bool input)
{
	if (input)
	{
		std::ifstream inStream(file);

		if (!inStream)
		{
			std::cerr << "Could not open file for reading " << file << std::endl;
			return (false);
		}
	}
	else
	{
		std::ofstream outStream(file);

		if (!outStream)
		{
			std::cerr << "Could not open file for writing " << file << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	doReplace(std::string inFile, std::string outFile,
				  std::string oldStr, std::string newStr)
{
	if (oldStr.size() == 0)
	{
		std::cerr << "Cannot replace nothing!" << std::endl;
		return (false);
	}

	std::ifstream	inStream(inFile);

	if (!verifyFile(inFile, 1))
		return (false);

	std::ofstream	outStream(outFile);

	if (!verifyFile(outFile, 0))
		return (false);

	std::string line;
	std::string fileContents;

	while (std::getline(inStream, line))
		fileContents += (line + '\n');
	inStream.close();

	replaceAllOccurrences(fileContents, oldStr, newStr);
	outStream << fileContents;

	return (true);
}

int		main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout	  			 <<
		"Usage: "	  << argv[0] <<
		" file_name old new"	 <<
		std::endl;

		return (1);
	}
	
	std::string	dstFile = argv[1];
	dstFile += ".replace";

	return (!(doReplace(argv[1], dstFile, argv[2], argv[3])));
}
