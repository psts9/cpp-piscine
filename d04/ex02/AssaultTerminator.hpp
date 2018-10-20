#ifndef ASSAULTTERMINATOR_H
# define ASSAULTTERMINATOR_H

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator& marine);
	~AssaultTerminator(void);

	AssaultTerminator&	operator=(AssaultTerminator& marine);

	ISpaceMarine*	clone(void) const;
	
	void	battleCry(void) const;
	void	rangedAttack(void) const;
	void	meleeAttack(void) const;

};

#endif
