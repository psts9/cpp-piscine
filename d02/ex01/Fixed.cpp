#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed(void) : point_(0)
{
	std::cout << "Default constructor called" << std::endl;

	return;
}

Fixed::Fixed(Fixed const& fixed)
{
	std::cout << "Copy constructor called" << std::endl;

	*this = fixed;

	return;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;

	this->point_ = (n << this->bits_);
	
	return;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float contructor called" << std::endl;

	this->point_ = roundf(f * (1 << this->bits_));

	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	return;
}

int		Fixed::getRawBits(void) const
{
	return (this->point_);
}

void	Fixed::setRawBits(int const raw)
{
	this->point_ = raw;

	return;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->point_ / (float)(1 << this->bits_));
}

int		Fixed::toInt(void) const
{
	return (this->point_ >> this->bits_);
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->point_ = rhs.getRawBits();

	return (*this);
}

std::ostream& operator<<(std::ostream& o, Fixed const& rhs)
{
	o << rhs.toFloat();

	return (o);
}
