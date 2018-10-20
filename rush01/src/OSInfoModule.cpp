#include <sys/utsname.h>

#include "OSInfoModule.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

OSInfoModule::OSInfoModule(void)
{
}

OSInfoModule::~OSInfoModule(void)
{
}

//~--------------------------------------------------------~
// Functions

std::string	OSInfoModule::getName(void) const
{
	return (std::string("OSInfo Module"));
}

std::vector<std::string> OSInfoModule::getFieldInfo(void) const
{
	struct utsname u;
	std::vector<std::string> fields;

	uname(&u);

	fields.push_back(u.sysname);
	fields.push_back(u.nodename);
	fields.push_back(u.release);
	fields.push_back(u.version);
	fields.push_back(u.machine);

	return (fields);
}

std::vector<std::string> OSInfoModule::getFieldNames(void) const
{
	std::vector<std::string> fieldnames;

	fieldnames.push_back("Sysname");
	fieldnames.push_back("Nodename");
	fieldnames.push_back("Release");
	fieldnames.push_back("Version");
	fieldnames.push_back("Machine");

	return (fieldnames);
}
