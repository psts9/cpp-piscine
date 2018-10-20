#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H

# include <string>
# include <vector>

class IMonitorModule
{
public:
	IMonitorModule(void);
	virtual ~IMonitorModule(void);
	virtual std::string	getName(void) const = 0;
	virtual std::vector<std::string> getFieldNames(void) const = 0;
	virtual std::vector<std::string> getFieldInfo(void) const = 0;

private:
	IMonitorModule(IMonitorModule const& m);

	IMonitorModule& operator=(IMonitorModule const& m);
};

#endif
