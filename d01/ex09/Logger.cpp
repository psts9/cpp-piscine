#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

#include "Logger.hpp"

Logger::Logger(std::string const &logFile) : logFile_(logFile)
{
	return;
}

Logger::~Logger(void)
{
	return;
}

void		Logger::logToFile(std::string const& str)
{
	std::ofstream outStream(this->logFile_, std::ios::app);

	outStream << str << std::endl;
	outStream.close();

	return;
}

void		Logger::logToConsole(std::string const& str)
{
	std::cout << str << std::endl;

	return;
}

std::string	getTimestamp(void)
{
	std::stringstream ss;

	std::time_t t	 = std::time(0);
	std::tm		*now = std::localtime(&t);

	ss			 << '['											<<
	std::setw(4) << std::setfill('0') << (now->tm_year + 1900)	<<
	std::setw(2) << std::setfill('0') << (now->tm_mon + 1)		<<
	std::setw(2) << std::setfill('0') << (now->tm_mday)			<<
	'_'															<<
	std::setw(2) << std::setfill('0') << (now->tm_hour)			<<
	std::setw(2) << std::setfill('0') << (now->tm_min)			<<
	std::setw(2) << std::setfill('0') << (now->tm_sec)			<<
				 	']';
	
	return (ss.str());
}

std::string	Logger::makeLogEntry(std::string const& str)
{
	return (getTimestamp() + ' ' + str);
}

void		Logger::log(std::string const& dest, std::string const& message)
{
	const static int	destCount = 2;

	std::string	logTab[destCount] =
	{
		"console",
		"file"
	};

	typedef void (Logger::*Logs)(std::string const& str);

	Logs	logFuncTab[destCount] =
	{
		&Logger::logToConsole,
		&Logger::logToFile
	};

	std::string logMessage = this->makeLogEntry(message);

	for (int i = 0; i < destCount; ++i)
	{
		if (logTab[i] == dest)
		{
			(this->*(logFuncTab[i]))(logMessage);
			return;
		}
	}

	std::cerr << dest << " is not a valid log destination!" << std::endl;

	return;
}
