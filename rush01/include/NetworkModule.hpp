#ifndef NETWORKMODULE_H
# define NETWORKMODULE_H

# include "IMonitorModule.hpp"

# define MM_NETWORK_THROUGHPUT

class NetworkModule : public IMonitorModule
{
public:
	NetworkModule(void);
	~NetworkModule(void);

	std::string getName(void) const;
	std::vector<std::string> getFieldNames(void) const;
	std::vector<std::string> getFieldInfo(void) const;

private:
	std::string	getNetworkThroughput(void) const;

	NetworkModule(NetworkModule const& m);

	NetworkModule& operator=(NetworkModule const& m);
};

#endif
