#ifndef TACTICALMARINE_H
# define TACTICALMARINE_H

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine(void);
	TacticalMarine(TacticalMarine& marine);
	~TacticalMarine(void);

	TacticalMarine&	operator=(TacticalMarine& marine);

	ISpaceMarine*	clone(void) const;
	
	void	battleCry(void) const;
	void	rangedAttack(void) const;
	void	meleeAttack(void) const;

};

#endif
