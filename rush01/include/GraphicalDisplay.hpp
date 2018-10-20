#ifndef GRAPHICALDISPLAY_H
# define GRAPHICALDISPLAY_H

#include <SFML/Graphics.hpp>

# include "IMonitorDisplay.hpp"

class GraphicalDisplay : public IMonitorDisplay
{
public:
	GraphicalDisplay(void);
	~GraphicalDisplay(void);

	void	display(std::vector<IMonitorModule*> const& m) const;

private:
	GraphicalDisplay(GraphicalDisplay const& d);

	GraphicalDisplay& operator=(GraphicalDisplay const& d);
};

#endif
