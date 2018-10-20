#include <iostream>

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

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;

	return;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->point_);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->point_ = raw;

	return;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->point_ = rhs.getRawBits();

	return (*this);
}
