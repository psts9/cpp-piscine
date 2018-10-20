#include <curses.h>

#include "KeyHandler.hpp"

//~--------------------------------------------------------~
// Init

void	KeyHandler::init(void)
{
	for (int i = 0; i < keyCount_; ++i)
		keys_[i] = false;
	
	return;
}

//~--------------------------------------------------------~
// Constructors & Destructor

KeyHandler::KeyHandler(void)
{
	init();

	return;
}

KeyHandler::KeyHandler(KeyHandler const& handler)
{
	*this = handler;

	return;
}

KeyHandler::~KeyHandler(void)
{
	return;
}

//~--------------------------------------------------------~
// Operators

KeyHandler& KeyHandler::operator=(KeyHandler const& key)
{
	for (int i = 0; i < keyCount_; ++i)
		keys_[i] = key.isPressed(i);

	return (*this);
}

//~--------------------------------------------------------~
// Functions

void	KeyHandler::readKeys(void)
{
	int c;

	while ((c = getch()) != ERR)
		keys_[c] = true;

	return;
}

bool	KeyHandler::isPressed(int keycode) const
{
	if (keycode > keyCount_ || keycode < 0)
		return (false);

	return (keys_[keycode]);
}

void	KeyHandler::reset(void)
{
	for (int i = 0; i < keyCount_; ++i)
		keys_[i] = false;

	return;
}

