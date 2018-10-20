#ifndef PROJECTILE_H
# define PROJECTILE_H

# include "GameEntity.hpp"

class Projectile : public GameEntity
{
public:
	Projectile(int x, int y, char c, Scene* scene, bool isDeadly);
	Projectile(Vec2 const& v, char c, Scene* scene, bool isDeadly);
	~Projectile(void);

	void	update(void);

private:
	Projectile(void);
	Projectile(Projectile const& p);

	void init(int x, int y, char c, Scene* scene, bool isDeadly);
};

#endif
