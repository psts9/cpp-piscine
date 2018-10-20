#include <iostream>

#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed		b(10);
	Fixed		c(42.42f);
	Fixed		d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl;

	a = a + b;
	std::cout << "a add b is " << a << std::endl;
	a = a - c;
	std::cout << "a sub c is " << a << std::endl;
	b = b * c;
	std::cout << "b mul c is " << b << std::endl;
	b = b / a;
	std::cout << "b div a is " << b << std::endl;

	std::cout << std::endl;

	Fixed	x;

	std::cout << x << std::endl;
	std::cout << ++x << std::endl;
	std::cout << x << std::endl;
	std::cout << x++ << std::endl;
	std::cout << x << std::endl;
	std::cout << x-- << std::endl;
	std::cout << x << std::endl;
	std::cout << --x << std::endl;
	std::cout << x << std::endl;


	std::cout << std::endl;

	std::cout << "max of " << a.toFloat() << " and " << b.toFloat() << " = " << Fixed::max(a, b) << std::endl;
	std::cout << "min of " << a.toFloat() << " and " << b.toFloat() << " = " << Fixed::min(a, b) << std::endl;

	Fixed const	ay(0);
	Fixed const bee(-1);
	Fixed const see(1);
	Fixed const dee(1);
	
	std::cout << "max of " << bee.toFloat() << " and " << see.toFloat() << " = " << Fixed::max(bee, see) << std::endl;
	std::cout << "min of " << ay.toFloat() << " and " << dee.toFloat() << " = " << Fixed::min(ay, dee) << std::endl;
	std::cout << "max of " << see.toFloat() << " and " << dee.toFloat() << " = " << Fixed::max(see, dee) << std::endl;
	std::cout << "min of " << see.toFloat() << " and " << bee.toFloat() << " = " << Fixed::min(see, bee) << std::endl;

	return (0);
}
