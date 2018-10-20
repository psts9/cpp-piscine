#ifndef TEXTDISPLAY_H
# define TEXTDISPLAY_H

# include <curses.h>

# include "IMonitorDisplay.hpp"

class TextDisplay : public IMonitorDisplay
{
public:
	TextDisplay(void);
	~TextDisplay(void);

	void	display(std::vector<IMonitorModule*> const& m) const;

private:
	TextDisplay(TextDisplay const& d);

	TextDisplay& operator=(TextDisplay const& d);
};

#endif
