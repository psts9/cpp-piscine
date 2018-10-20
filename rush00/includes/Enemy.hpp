#ifndef ENEMY_H
# define ENEMY_H

# include "GameEntity.hpp"

class Enemy : public GameEntity
{
public:
	Enemy(int x, int y, char c, Scene* scene);
	Enemy(Vec2 const& v, char c, Scene* scene);
	~Enemy(void);

	void	update(void);

private:
	Enemy(void);
	Enemy(Enemy const& enemy);

	void fire(void);
	
	void init(int x, int y, char c, Scene* scene);
};

#endif
