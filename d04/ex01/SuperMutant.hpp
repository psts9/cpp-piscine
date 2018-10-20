#ifndef SUPERMUTANT_H
# define SUPERMUTANT_H

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant(void);
	virtual ~SuperMutant(void);

	virtual void takeDamage(int amount);

private:
	SuperMutant(int hp, std::string const& type);
	SuperMutant(SuperMutant const& superMutant);

};

#endif
