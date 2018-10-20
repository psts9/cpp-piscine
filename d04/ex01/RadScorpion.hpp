#ifndef RADSCORPION_H
# define RADSCORPION_H

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion(void);
	virtual ~RadScorpion(void);

private:
	RadScorpion(int hp, std::string const& type);
	RadScorpion(RadScorpion const& radScorpion);

};

#endif
