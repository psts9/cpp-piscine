#ifndef FIXED_H
# define FIXED_H

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const& fixed);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed& operator=(Fixed const& rhs);

private:
	int					point_;
	static const int	bits_ = 8;
};

#endif
