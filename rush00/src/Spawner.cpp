#include <cstdlib>
#include <string>

#include "Spawner.hpp"
#include "Vec2.hpp"
#include "Scene.hpp"
#include "Enemy.hpp"

//~--------------------------------------------------------~
// Init

void	Spawner::init(Scene* scene)
{
	scene_  = scene;

	return;
}

//~--------------------------------------------------------~
// Constructors & Destructor

Spawner::Spawner(void)
{
	init(NULL);

	return;
}

Spawner::Spawner(Scene* scene)
{
	init(scene);

	return;
}

Spawner::Spawner(Spawner const& spawner)
{
	*this = spawner;

	return;
}

Spawner::~Spawner(void)
{
	return;
}

//~--------------------------------------------------------~
// Gets

Scene*	Spawner::getScene(void) const
{
	return (scene_);
}

//~--------------------------------------------------------~
// Operators

Spawner& Spawner::operator=(Spawner const& spawner)
{
	scene_ = spawner.getScene();

	return (*this);
}

//~--------------------------------------------------------~
// Functions

typedef void (Spawner::*spawnFunc)(void);

static const int	g_entitySpawnTypes = 1;

const std::string	g_spawnTypes[] =
{
	"enemy",
	"boss"
};

const spawnFunc spawnFuncs[] =
{
	&Spawner::spawnEnemy
};

void	Spawner::spawn(std::string const& type)
{
	for (int i = 0; i < g_entitySpawnTypes; ++i)
	{
		if (g_spawnTypes[i] == type)
		{
			(this->*(spawnFuncs[i]))();
			return;
		}
	}

	return;
}

static const int g_enemyCharCount = 2;

const	char	g_enemyChars[] =
{
	'=',
	'<',
};

void	Spawner::spawnEnemy(void)
{
	Screen screen;

	Enemy* enemy = new Enemy(screen.getWidth(), rand() % screen.getHeight(), g_enemyChars[rand() % g_enemyCharCount], scene_);
	enemy->setEntityIdx(scene_->addEntity(enemy));

	return;
}
