#include <unistd.h>
#include <limits.h>

#include "HostnameModule.hpp"

#define HOST_NAME_MAX	_POSIX_HOST_NAME_MAX
#define LOGIN_NAME_MAX	_POSIX_LOGIN_NAME_MAX

//~--------------------------------------------------------~
// Constructors & Destructor

HostnameModule::HostnameModule(void)
{
}

HostnameModule::~HostnameModule(void)
{
}

//~--------------------------------------------------------~
// Functions

std::string	HostnameModule::getHostname(void) const
{
	char hostname[HOST_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);

	return (std::string(hostname));
}

std::string	HostnameModule::getUsername(void) const
{
	char username[LOGIN_NAME_MAX];

	getlogin_r(username, LOGIN_NAME_MAX);

	return (std::string(username));
}

std::string HostnameModule::getName(void) const
{
	return (std::string("Hostname Module"));
}

std::vector<std::string> HostnameModule::getFieldInfo(void) const
{
	std::vector<std::string> fields;

	fields.push_back(getHostname());
	fields.push_back(getUsername());

	return (fields);
}

std::vector<std::string> HostnameModule::getFieldNames(void) const
{
	std::vector<std::string> fieldnames;

	fieldnames.push_back("Hostname");
	fieldnames.push_back("Username");

	return (fieldnames);
}
