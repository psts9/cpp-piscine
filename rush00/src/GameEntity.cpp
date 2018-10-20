#include <cstdlib>
#include <math.h>

#include "GameEntity.hpp"

//~-----------------------------------------------------------~
// Constructors & Destructor

GameEntity::GameEntity(void)
{
	return;
}

GameEntity::GameEntity(GameEntity const& entity)
{
	*this = entity;

	return;
}

GameEntity::~GameEntity(void)
{
	return;
}

//~--------------------------------------------------------~
// Operators

GameEntity& GameEntity::operator=(GameEntity const& entity)
{
	this->position_ = entity.getPosition();

	return (*this);
}

//~--------------------------------------------------------~
// Gets

double	GameEntity::getX(void) const
{
	return (this->position_.x);
}

double	GameEntity::getY(void) const
{
	return (this->position_.y);
}

Vec2	GameEntity::getPosition(void) const
{
	return (this->position_);
}

int		GameEntity::getCharacter(void) const
{
	return (this->character_);
}

int		GameEntity::getEntityIdx(void) const
{
	return (this->entityIdx_);
}

//~--------------------------------------------------------~
// Sets

void	GameEntity::setX(double n)
{
	this->position_.x = n;

	return;
}

void	GameEntity::setY(double n)
{
	this->position_.y = n;

	return;
}

void	GameEntity::setPosition(Vec2 const& v)
{
	this->position_ = v;

	return;
}

void	GameEntity::setEntityIdx(int n)
{
	this->entityIdx_ = n;

	return;
}

//~--------------------------------------------------------~
// Incs

void	GameEntity::movX(double n)
{
	this->position_.x += n;

	return;
}

void	GameEntity::movY(double n)
{
	this->position_.y += n;

	return;
}

void	GameEntity::incPosition(Vec2 const& v)
{
	this->position_ = this->position_ + v;

	return;
}

void	GameEntity::decPosition(Vec2 const& v)
{
	this->position_ = this->position_ - v;

	return;
}

//~--------------------------------------------------------~
// Functions

void	GameEntity::update(void)
{
	return;
}

void	GameEntity::display(Screen const& screen) const
{
	screen.draw(position_, character_);

	return;
}

GameEntity*	GameEntity::getCollision(void) const
{
	Vec2	predictPos;

	for (int i = 0; i < scene_->getEntityCount(); ++i)
	{
		if (scene_->getEntity(i) && getEntityIdx() != i)
		{
			predictPos = position_;

			if ((int)scene_->getEntity(i)->getY() == (int)position_.y)
			{
				if (fabs(scene_->getEntity(i)->getX() - position_.x) < 1.0)
					return (scene_->getEntity(i));
			}
		}
	}

	return (NULL);
}

bool	GameEntity::isDeadly(void) const
{
	return (isDeadly_);
}
