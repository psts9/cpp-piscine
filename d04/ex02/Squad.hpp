#ifndef SQUAD_H
# define SQUAD_H

# include "ISquad.hpp"

class Squad : public ISquad
{
public:
	Squad(void);
	Squad(Squad const& squad);
	~Squad(void);

	Squad& operator=(Squad const& squad);

	int			  getCount(void) const;
	ISpaceMarine* getUnit(int unitIndex) const;
	
	int push(ISpaceMarine* marine);

private:
	ISpaceMarine**	squad_;
	int				unitCount_;
};

#endif
