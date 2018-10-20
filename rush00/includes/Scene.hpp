#ifndef SCENE_H
# define SCENE_H

class Player;
class GameEntity;
class Screen;
class Spawner;

class Scene
{
public:
	Scene(void);
	~Scene(void);

	GameEntity*	getEntity(int idx) const;
	int			getEntityCount(void) const;

	int			addEntity(GameEntity* entity);
	void		removeEntity(int idx);

	void		update(void);
	void		display(Screen const& screen);

	int			getScore(void) const;
	void		addScore(void);
	void		resetScore(void);

	void		clear(void);

private:
	Scene(Scene const& scene);

	Scene& operator=(Scene const& scene);

	void init(void);
	void doSpawning(void);

	static const int maxEntities_ = 1024;

	GameEntity** entities_;
	Spawner*	 spawner_;

	int	score_;
};

#endif
