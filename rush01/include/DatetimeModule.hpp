#ifndef DATETIMEMODULE_H
# define DATETIMEMODULE_H

# include "IMonitorModule.hpp"

# define MM_DATETIME_DATE 0
# define MM_DATETIME_TIME 1

class DatetimeModule : public IMonitorModule
{
public:
	DatetimeModule(void);
	~DatetimeModule(void);

	std::string getName(void) const;
	std::vector<std::string> getFieldNames(void) const;
	std::vector<std::string> getFieldInfo(void) const;

private:
	std::string	getTime(void) const;
	std::string getDate(void) const;

	DatetimeModule(DatetimeModule const& m);

	DatetimeModule& operator=(DatetimeModule const& m);
};

#endif
