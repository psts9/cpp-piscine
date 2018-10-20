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

	Fixed& operator=(Fixed const& rhs);

private:
	int					point_;
	static const int	bits_ = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);

#endif
