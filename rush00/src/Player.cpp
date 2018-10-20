#include <curses.h>

#include "Player.hpp"
#include "Screen.hpp"
#include "Projectile.hpp"

//~--------------------------------------------------------~
// Init

void	Player::init(int x, int y, int c, int col1, int col2, KeyHandler* handler, Scene* scene, Game *game)
{
	this->position_.x = x;
	this->position_.y = y;
	this->character_ = c;
	this->colors_.x = col1;
	this->colors_.y = col2;
	this->keyHandler_ = handler;
	this->scene_ = scene;
	this->game_ = game;
	this->isDeadly_ = false;
	this->lives_ = 3;

	return;
}

//~--------------------------------------------------------~
// Constructors & Destructor

#include <stdlib.h>

Player::Player(void)
{
	init(0, 0, '>', 0, 0, NULL, NULL, NULL);

	return;
}

Player::Player(int x, int y, int c, KeyHandler* handler, Scene* scene, Game* game)
{
	init(x, y, c, 7, 7, handler, scene, game);

	return;
}

Player::Player(Player const& player)
{
	*this = player;

	return;
}

Player::~Player(void)
{
	return;
}

//~--------------------------------------------------------~
// Gets

int	Player::getLives(void) const
{
	return (lives_);
}

//~--------------------------------------------------------~
// Functions

void	Player::fire(void)
{
	Projectile* p = new Projectile(this->getX() + 1, this->getY(), '~', scene_, true);

	p->setEntityIdx(scene_->addEntity(p));

	return;
}

#include <cstdlib>

void	Player::update(void)
{
	Screen screenInfo;

	int movx = 0;
	int movy = 0;

	if (keyHandler_->isPressed(KEY_DOWN))
		movy += 1;
	if (keyHandler_->isPressed(KEY_UP))
		movy -= 1;
	if (keyHandler_->isPressed('z') || keyHandler_->isPressed('Z'))
		fire();

	if (position_.x + movx >= 0 && position_.x + movx < screenInfo.getWidth())
		this->movX(movx);
	if (position_.y + movy >= 0 && position_.y + movy < screenInfo.getHeight())
		this->movY(movy);

	GameEntity*	collider = NULL;

	collider = getCollision();

	if (collider != NULL)
	{
		--lives_;

		collider->movX(-2);

		if (lives_ == 0)
			game_->exit();
	}

	return;
}
