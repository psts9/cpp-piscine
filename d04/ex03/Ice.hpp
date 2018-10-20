#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(Ice const& ice);
	~Ice(void);

	AMateria* clone(void) const;
	
	void	use(ICharacter& target);
};

#endif
