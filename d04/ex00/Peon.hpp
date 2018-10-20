#ifndef PEON_H
# define PEON_H

#include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string const& name);
	Peon(Peon const& peon);
	virtual ~Peon(void);

	virtual void getPolyMorphed(void) const;

private:
	Peon(void);
};

#endif
