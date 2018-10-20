#ifndef GAMEENTITY_H
# define GAMEENTITY_H

# include "Vec2.hpp"
# include "Screen.hpp"
# include "Scene.hpp"

class GameEntity
{
public:
	GameEntity(void);
	GameEntity(GameEntity const& entity);
	virtual ~GameEntity(void);

	GameEntity& operator=(GameEntity const& entity);

	double	getX(void) const;
	double	getY(void) const;
	Vec2	getPosition(void) const;
	int		getCharacter(void) const;

	void	setX(double n);
	void	setY(double n);
	void	setPosition(Vec2 const& v);

	void	movX(double n);
	void	movY(double n);

	void	incPosition(Vec2 const& v);
	void	decPosition(Vec2 const& v);

	void	setEntityIdx(int n);
	int		getEntityIdx(void) const;

	GameEntity*		getCollision(void) const;
	virtual bool	isDeadly(void) const;

	virtual void	update(void) = 0;

	void		 display(Screen const& screen) const;

protected:
	Vec2	position_;
	Vec2	colors_;
	int		character_;

	Scene*	scene_;
	int		entityIdx_;

	bool	isDeadly_;
};

#endif
