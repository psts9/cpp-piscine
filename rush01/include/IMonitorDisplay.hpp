#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

# include <vector>

# include "IMonitorModule.hpp"

class IMonitorDisplay
{
public:
	IMonitorDisplay(void);
	virtual ~IMonitorDisplay(void);
	virtual	void	display(std::vector<IMonitorModule*> const& m) const = 0;

private:
	IMonitorDisplay(IMonitorDisplay const& m);

	IMonitorDisplay& operator=(IMonitorDisplay const& m);
};

#endif
