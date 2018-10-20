#ifndef RAMMODULE_H
# define RAMMODULE_H

# include "IMonitorModule.hpp"

# define MM_RAM_SIZE	 0
# define MM_RAM_TOTAL	 1
# define MM_RAM_WIRED	 2
# define MM_RAM_ACTIVE	 3
# define MM_RAM_INACTIVE 4
# define MM_RAM_FREE	 5

class RAMModule : public IMonitorModule
{
public:
	RAMModule(void);
	~RAMModule(void);

	std::string getName(void) const;
	std::vector<std::string> getFieldNames(void) const;
	std::vector<std::string> getFieldInfo(void) const;

private:
	std::string getPhysicalMemory(void) const;

	RAMModule(RAMModule const& m);

	RAMModule& operator=(RAMModule const& m);
};

#endif
