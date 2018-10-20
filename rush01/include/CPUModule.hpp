#ifndef CPUMODULE_H
# define CPUMODULE_H

# include "IMonitorModule.hpp"

# define MM_CPU_MODEL		0
# define MM_CPU_CORECOUNT	1
# define MM_CPU_USAGE		2
# define MM_CPU_LOAD		3

class CPUModule : public IMonitorModule
{
public:
	CPUModule(void);
	~CPUModule(void);

	std::string getName(void) const;
	std::vector<std::string> getFieldNames(void) const;
	std::vector<std::string> getFieldInfo(void) const;

private:
	std::string getModel(void) const;
	std::string getCoreCount(void) const;
	std::string getUsage(void) const;
	std::string getLoad(void) const;

	CPUModule(CPUModule const& m);

	CPUModule& operator=(CPUModule const& m);
};

#endif
