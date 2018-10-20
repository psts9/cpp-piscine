#include <sstream>

#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach.h>

#include "RAMModule.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

RAMModule::RAMModule(void)
{
}

RAMModule::~RAMModule(void)
{
}

//~--------------------------------------------------------~
// Functions

std::string	RAMModule::getPhysicalMemory(void) const
{
	std::stringstream ss;	
	uint64_t	value = 0;
	size_t		len = sizeof(value);

	sysctlbyname("hw.memsize", &value, &len, NULL, 0);

	ss << value;

	return (ss.str());
}

std::string	RAMModule::getName(void) const
{
	return (std::string("RAM Module"));
}

std::vector<std::string> RAMModule::getFieldInfo(void) const
{
	std::stringstream		 ss;
	std::vector<std::string> fields;

	fields.push_back(getPhysicalMemory());

	mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
	vm_statistics_data_t vmstat;

	host_statistics(mach_host_self(), HOST_VM_INFO, reinterpret_cast<host_info_t>(&vmstat), &count);

	uint64_t total = vmstat.wire_count + vmstat.active_count + vmstat.inactive_count + vmstat.free_count;
	uint64_t wired = vmstat.wire_count;
	uint64_t active = vmstat.active_count;
	uint64_t inactive = vmstat.inactive_count;
	uint64_t freeMem = vmstat.free_count; 

	ss << total;
	fields.push_back(ss.str());
	ss.str("");
	ss << wired;
	fields.push_back(ss.str());
	ss.str("");
	ss << active;
	fields.push_back(ss.str());
	ss.str("");
	ss << inactive;
	fields.push_back(ss.str());
	ss.str("");
	ss << freeMem;
	fields.push_back(ss.str());

	return (fields);
}

std::vector<std::string> RAMModule::getFieldNames(void) const
{
	std::vector<std::string> fieldnames;

	fieldnames.push_back("Physical Memory");
	fieldnames.push_back("Total");
	fieldnames.push_back("Wired");
	fieldnames.push_back("Active");
	fieldnames.push_back("Inactive");
	fieldnames.push_back("Free");

	return (fieldnames);
}
