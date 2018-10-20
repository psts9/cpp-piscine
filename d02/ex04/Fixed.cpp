#include <cmath>

#include "Fixed.hpp"

//~-----------------------------------------------------------~//
// Constructors

Fixed::Fixed(void) : point_(0)
{
	return;
}

Fixed::Fixed(Fixed const& fixed)
{
	*this = fixed;

	return;
}

Fixed::Fixed(const int n)
{
	this->point_ = (n << this->bits_);
	
	return;
}

Fixed::Fixed(const float f)
{
	this->point_ = roundf(f * (1 << this->bits_));

	return;
}




//~-----------------------------------------------------------~//
// Destructor

Fixed::~Fixed(void)
{
	return;
}




//~-----------------------------------------------------------~//
// Gets

int		Fixed::getRawBits(void) const
{
	return (this->point_);
}




//~-----------------------------------------------------------~//
// Sets

void	Fixed::setRawBits(int const raw)
{
	this->point_ = raw;

	return;
}




//~-----------------------------------------------------------~//
// Conversions

float	Fixed::toFloat(void) const
{
	return ((float)this->point_ / (float)(1 << this->bits_));
}

int		Fixed::toInt(void) const
{
	return (this->point_ >> this->bits_);
}




//~-----------------------------------------------------------~//
// Operators

// Assignment
Fixed&  Fixed::operator=(Fixed const& rhs)
{
	this->point_ = rhs.getRawBits();

	return (*this);
}

// Comparisons
bool	Fixed::operator>(Fixed const& rhs)
{
	return (this->point_ > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const& rhs)
{
	return (this->point_ < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const& rhs)
{
	return (this->point_ >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const& rhs)
{
	return (this->point_ <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const& rhs)
{
	return (this->point_ == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const& rhs)
{
	return (this->point_ != rhs.getRawBits());
}


// Arithmetic
Fixed	Fixed::operator+(Fixed const& rhs)
{
	Fixed fixed;

	fixed.setRawBits(this->point_ + rhs.getRawBits());

	return (fixed);
}

Fixed	Fixed::operator-(Fixed const& rhs)
{
	Fixed fixed;

	fixed.setRawBits(this->point_ - rhs.getRawBits());

	return (fixed);
}

Fixed	Fixed::operator*(Fixed const& rhs)
{
	Fixed fixed;

	fixed.setRawBits((this->point_ * rhs.getRawBits()) >> 8);

	return (fixed);
}

Fixed	Fixed::operator/(Fixed const& rhs)
{
	Fixed	fixed;

	fixed.setRawBits(((this->point_) << 8) / rhs.getRawBits());

	return (fixed);
}

// Prefix / Postfix
Fixed&	Fixed::operator++(void)
{
	++this->point_;

	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);

	++this->point_;

	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	--this->point_;

	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);

	--this->point_;

	return (temp);
}

// IO
std::ostream& operator<<(std::ostream& o, Fixed const& rhs)
{
	o << rhs.toFloat();

	return (o);
}




//~-----------------------------------------------------------~//
// Utility

Fixed&			Fixed::max(Fixed& lhs, Fixed& rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed const&	Fixed::max(Fixed const& lhs, Fixed const& rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed&			Fixed::min(Fixed& lhs, Fixed& rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}


Fixed const&	Fixed::min(Fixed const& lhs, Fixed const& rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}
