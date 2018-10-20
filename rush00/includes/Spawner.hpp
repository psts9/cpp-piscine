#ifndef SPAWNER_H
# define SPAWNER_H

class Scene;
class Screen;
class Enemy;

class Spawner
{
public:
	Spawner(Scene* scene);
	Spawner(Spawner const& spawner);
	~Spawner(void);

	Spawner& operator=(Spawner const& spawner);

	Scene*			getScene(void) const;
	Screen const*	getScreen(void) const;

	void	spawn(std::string const& type);

	void	spawnEnemy(void);

private:
	Spawner(void);

	void	init(Scene* scene);

	Scene*			scene_;
};

#endif
