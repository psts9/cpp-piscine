#ifndef OSINFOMODULE_H
# define OSINFOMODULE_H

# include "IMonitorModule.hpp"

# define MM_OSINFO_SYSNAME	0
# define MM_OSINFO_NODENAME	1
# define MM_OSINFO_RELEASE	2
# define MM_OSINFO_VERSION	3
# define MM_OSINFO_MACHINE	4

class OSInfoModule : public IMonitorModule
{
public:
	OSInfoModule(void);
	~OSInfoModule(void);

	std::string getName(void) const;
	std::vector<std::string> getFieldNames(void) const;
	std::vector<std::string> getFieldInfo(void) const;

private:
	OSInfoModule(OSInfoModule const& m);

	OSInfoModule& operator=(OSInfoModule const& m);
};

#endif
