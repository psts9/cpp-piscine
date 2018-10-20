#include <time.h>

#include "DatetimeModule.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

DatetimeModule::DatetimeModule(void)
{
}

DatetimeModule::~DatetimeModule(void)
{
}

//~--------------------------------------------------------~
// Functions

std::string DatetimeModule::getDate(void) const
{
	time_t		now = time(0);
	struct tm	tstruct;
	char		buf[80];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

	return (buf);
}

std::string	DatetimeModule::getTime(void) const
{
	time_t		now = time(0);
	struct tm	tstruct;
	char		buf[80];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);

	return (buf);
}

std::string DatetimeModule::getName(void) const
{
	return (std::string("Datetime Module"));
}

std::vector<std::string> DatetimeModule::getFieldInfo(void) const
{
	std::vector<std::string> fields;

	fields.push_back(getDate());
	fields.push_back(getTime());

	return (fields);
}

std::vector<std::string> DatetimeModule::getFieldNames(void) const
{
	std::vector<std::string> fieldnames;

	fieldnames.push_back("Date");
	fieldnames.push_back("Time");

	return (fieldnames);
}
