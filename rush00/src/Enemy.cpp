#include <cstdlib>

#include "Enemy.hpp"
#include "Projectile.hpp"

//~--------------------------------------------------------~
// Init

void	Enemy::init(int x, int y, char c, Scene* scene)
{
	this->entityIdx_ = -1;
	this->position_.x = x;
	this->position_.y = y;
	this->character_ = c;
	this->scene_ = scene;
	this->isDeadly_ = false;

	return;
}

//~--------------------------------------------------------~
// Constructors & Destructor

Enemy::Enemy(void)
{
	init(0, 0, '$', NULL);

	return;
}

Enemy::Enemy(int x, int y, char c, Scene* scene)
{
	init(x, y, c, scene);

	return;
}

Enemy::Enemy(Vec2 const& v, char c, Scene* scene)
{
	init(v.x, v.y, c, scene);

	return;
}

Enemy::Enemy(Enemy const& enemy)
{
	*this = enemy;

	return;
}

Enemy::~Enemy(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	Enemy::fire(void)
{
	Projectile* p = new Projectile(this->getX() - 1, this->getY(), '-', scene_, false);

	p->setEntityIdx(scene_->addEntity(p));

	return;
}

void	Enemy::update(void)
{

	if (position_.x < 0)
	{
		scene_->removeEntity(entityIdx_);
		return;
	}

	GameEntity* collider = getCollision();

	if (collider != NULL)
	{
		if (collider->isDeadly() == true)
		{
			scene_->addScore();
			scene_->removeEntity(collider->getEntityIdx());
			scene_->removeEntity(entityIdx_);
			return;
		}
	}

	if (rand() % 10000 > 9950)
		fire();

	if (rand() % 10000 > 9900)
	{
		if (rand() % 2 == 0)
		{
			Screen screenInfo;

			if (position_.y + 1 < screenInfo.getHeight())
				this->movY(1);
		}
		else
		{
			if (position_.y - 1 >= 0)
				this->movY(-1);
		}
	}

	this->movX(-0.5);

	return;
}
