#include <sstream>

#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>

#include "NetworkModule.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

NetworkModule::NetworkModule(void)
{
}

NetworkModule::~NetworkModule(void)
{
}

//~--------------------------------------------------------~
// Functions

std::string	NetworkModule::getNetworkThroughput(void) const
{
	/* Copied from stackoverflow. Thanks Stefan, you're the man for figuring this out */

	std::stringstream ss;

	int		mib[] = { CTL_NET, PF_ROUTE, 0, 0, NET_RT_IFLIST2, 0 };
	char	*buf;
	size_t	len = 1024;

	sysctl(mib, 6, NULL, &len, NULL, 0);
	buf = new char[len];
	sysctl(mib, 6, buf, &len, NULL, 0);

	char *lim = buf + len;
	char *next = NULL;

	static u_int64_t previbytes;
	static u_int64_t prevobytes;

	u_int64_t totalibytes = 0;
	u_int64_t totalobytes = 0;

	for (next = buf; next < lim; )
	{
		struct if_msghdr *ifm = reinterpret_cast<struct if_msghdr*>(next);
		next += ifm->ifm_msglen;

		if (ifm->ifm_type == RTM_IFINFO2)
		{
			struct if_msghdr2 *if2m = reinterpret_cast<struct if_msghdr2*>(ifm);

			totalibytes += if2m->ifm_data.ifi_ibytes;
			totalobytes += if2m->ifm_data.ifi_obytes;
		}
	}

	ss << "InputBytes: " << (totalibytes - previbytes) / 1048576.0 << "M" << ", OutputBytes: " << (totalobytes - prevobytes) / 1048576.0 << "M";

	previbytes = totalibytes;
	prevobytes = totalobytes;

	delete buf;

	return (ss.str());
}

std::string	NetworkModule::getName(void) const
{
	return (std::string("Network Module"));
}

std::vector<std::string> NetworkModule::getFieldInfo(void) const
{
	std::vector<std::string> fields;

	fields.push_back(getNetworkThroughput());

	return (fields);
}

std::vector<std::string> NetworkModule::getFieldNames(void) const
{
	std::vector<std::string> fieldnames;

	fieldnames.push_back("Network Throughput");

	return (fieldnames);
}
