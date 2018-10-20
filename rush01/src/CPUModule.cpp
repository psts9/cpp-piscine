#include <sstream>

#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <mach/processor_info.h>
#include <mach/mach_host.h>
#include <unistd.h>

#include "CPUModule.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

CPUModule::CPUModule(void)
{
}

CPUModule::~CPUModule(void)
{
}

//~--------------------------------------------------------~
// Functions

std::string	CPUModule::getModel(void) const
{
	char	buf[128];
	size_t	buflen = 128;

	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

	return (buf);
}

std::string CPUModule::getCoreCount(void) const
{
	std::stringstream ss;
	int	coreCount = sysconf(_SC_NPROCESSORS_ONLN);

	ss << coreCount;

	return (ss.str());
}

std::string CPUModule::getUsage(void) const
{
	/* Couldn't figure this out on my own. Code stolen from Github. Thanks whoever did this */

	std::stringstream ss;

	processor_cpu_load_info_t	cpuLoad;
	mach_msg_type_number_t		processorMsgCount;
	natural_t					processorCount;

	static uint64_t prevTotalSystemTime, prevTotalUserTime, prevTotalIdleTime;

	uint64_t totalSystemTime = 0, totalUserTime = 0, totalIdleTime = 0;

	host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &processorCount, reinterpret_cast<processor_info_array_t *>(&cpuLoad), &processorMsgCount);

	for (natural_t i = 0; i < processorCount; ++i)
	{
		uint64_t system = 0, user = 0, idle = 0;

		system = cpuLoad[i].cpu_ticks[CPU_STATE_SYSTEM];
		user   = cpuLoad[i].cpu_ticks[CPU_STATE_USER] + cpuLoad[i].cpu_ticks[CPU_STATE_NICE];
		idle   = cpuLoad[i].cpu_ticks[CPU_STATE_IDLE];

		totalSystemTime += system;
		totalUserTime   += user;
		totalIdleTime   += idle;
	}

	uint64_t deltaTotalSystemTime = totalSystemTime - prevTotalSystemTime;
	uint64_t deltaTotalUserTime   = totalUserTime - prevTotalUserTime;
	uint64_t deltaTotalIdleTime   = totalIdleTime - prevTotalIdleTime;

	prevTotalSystemTime	= totalSystemTime;
	prevTotalUserTime	= totalUserTime;
	prevTotalIdleTime	= totalIdleTime;

	uint64_t total = deltaTotalSystemTime + deltaTotalUserTime + deltaTotalIdleTime;

	double onePercent = total / 100.0f;

	ss << "system: " << deltaTotalSystemTime / onePercent << "% ";
	ss << "user: " << deltaTotalUserTime / onePercent << "% ";
	ss << "idle: " << deltaTotalIdleTime / onePercent << "%";

	return (ss.str());
}

std::string	CPUModule::getLoad(void) const
{
	std::stringstream ss;
	double avg[3];

	getloadavg(avg, 3);

	ss << avg[0] << ", " << avg[1] << ", " << avg[2];

	return (ss.str());
}

std::string CPUModule::getName(void) const
{
	return (std::string("CPU Module"));
}

std::vector<std::string> CPUModule::getFieldInfo(void) const
{
	std::vector<std::string> fields;

	fields.push_back(getModel());
	fields.push_back(getCoreCount());
	fields.push_back(getUsage());
	fields.push_back(getLoad());

	return (fields);
}

std::vector<std::string> CPUModule::getFieldNames(void) const
{
	std::vector<std::string> fieldnames;

	fieldnames.push_back("Model");
	fieldnames.push_back("Core Count");
	fieldnames.push_back("Usage");
	fieldnames.push_back("Load Avg");

	return (fieldnames);
}
