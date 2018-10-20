#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const& fixed);
	Fixed(const int n);
	Fixed(const float f);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed&		max(Fixed& lhs, Fixed& rhs);
	static Fixed const&	max(Fixed const& lhs, Fixed const& rhs);

	static Fixed&		min(Fixed& lhs, Fixed& rhs);
	static Fixed const& min(Fixed const& lhs, Fixed const& rhs);

	Fixed&	operator=(Fixed const& rhs);
	bool	operator>(Fixed const& rhs);
	bool	operator<(Fixed const& rhs);
	bool	operator>=(Fixed const& rhs);
	bool	operator<=(Fixed const& rhs);
	bool	operator==(Fixed const& rhs);
	bool	operator!=(Fixed const& rhs);
	Fixed	operator+(Fixed const& rhs);
	Fixed	operator-(Fixed const& rhs);
	Fixed	operator*(Fixed const& rhs);
	Fixed	operator/(Fixed const& rhs);
	Fixed&	operator++(void);	// Prefix
	Fixed	operator++(int);	// Postfix
	Fixed&	operator--(void);	// Prefix
	Fixed	operator--(int);	// Postfix

private:
	int					point_;
	static const int	bits_ = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);

#endif
