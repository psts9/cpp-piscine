#ifndef HOSTNAMEMODULE_H
# define HOSTNAMEMODULE_H

# include "IMonitorModule.hpp"

# define MM_HOSTNAME_HOSTNAME 0
# define MM_HOSTNAME_USERNAME 1

class HostnameModule : public IMonitorModule
{
public:
	HostnameModule(void);
	~HostnameModule(void);

	std::string getName(void) const;
	std::vector<std::string> getFieldNames(void) const;
	std::vector<std::string> getFieldInfo(void) const;

private:
	std::string getUsername(void) const;
	std::string getHostname(void) const;

	HostnameModule(HostnameModule const& m);

	HostnameModule& operator=(HostnameModule const& m);
};

#endif
