#include <cstdlib>

#include "Projectile.hpp"
#include "Scene.hpp"

//~--------------------------------------------------------~
// Init

void	Projectile::init(int x, int y, char c, Scene* scene, bool isDeadly)
{
	this->entityIdx_ = -1;
	this->position_.x = x;
	this->position_.y = y;
	this->character_ = c;
	this->scene_ = scene;
	this->isDeadly_ = isDeadly;

	return;
}

//~--------------------------------------------------------~
// Constructors & Destructor

Projectile::Projectile(void)
{
	init(0, 0, '~', NULL, false);

	return;
}

Projectile::Projectile(int x, int y, char c, Scene* scene, bool isDeadly)
{
	init(x, y, c, scene, isDeadly);

	return;
}

Projectile::Projectile(Vec2 const& v, char c, Scene* scene, bool isDeadly)
{
	init(v.x, v.y, c, scene, isDeadly);

	return;
}

Projectile::Projectile(Projectile const& p)
{
	*this = p;

	return;
}

Projectile::~Projectile(void)
{
	return;
}

//~--------------------------------------------------------~
// Functions

void	Projectile::update(void)
{
	Screen screenInfo;

	if (position_.x >= screenInfo.getWidth())
	{
		scene_->removeEntity(entityIdx_);
		return;
	}

	if (isDeadly_)
		this->movX(1);
	else
		this->movX(-1);

	return;
}
