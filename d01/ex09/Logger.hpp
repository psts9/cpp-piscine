#ifndef LOGGER_H
# define LOGGER_H

# include <string>

class Logger
{
public:
	Logger(std::string const& logFile);
	~Logger(void);

	void	log(std::string const& dest, std::string const& message);

private:
	void		logToFile(std::string const& str);
	void		logToConsole(std::string const& str);
	std::string	makeLogEntry(std::string const& str);

	std::string const&	logFile_;
};

#endif
