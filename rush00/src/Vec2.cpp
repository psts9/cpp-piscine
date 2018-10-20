#include "Vec2.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Vec2::Vec2(void) : x(0), y(0)
{
	return;
}

Vec2::Vec2(double x_, double y_) : x(x_), y(y_)
{
	return;
}

Vec2::Vec2(Vec2 const& v)
{
	*this = v;

	return;
}

Vec2::~Vec2(void)
{
	return;
}

//~--------------------------------------------------------~
// Operators

Vec2& Vec2::operator=(Vec2 const& v)
{
	this->x = v.x;
	this->y = v.y;

	return (*this);
}

Vec2 Vec2::operator+(Vec2 const& v)
{
	Vec2 temp = *this;

	temp.x += v.x;
	temp.y += v.y;

	return (temp);
}

Vec2 Vec2::operator-(Vec2 const& v)
{
	Vec2 temp = *this;

	temp.x -= v.x;
	temp.y -= v.y;

	return (temp);
}

bool Vec2::operator==(Vec2 const& v) const
{
	return (this->x == v.x && this->y == v.y);
}
