#include <iostream>

struct Data 
{
	std::string s1;
	int	n;
	std::string s2;
};

unsigned int xorshift32(void)
{
	static unsigned int state = 0x23456789;
	state ^= state << 13;
	state ^= state >> 17;
	state ^= state << 5;
	return (state);
}

unsigned int randChars(void)
{
	char const* s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char c[4];

	for (int i = 0; i < 4; ++i)
	{
		c[i] = s[xorshift32() % 62];
		std::cout << c[i];
	}
	std::cout << std::endl;

	int *i = reinterpret_cast<int *>(c);

	return (*i);
}

void*	serialize(void)
{
	int*	data = new int[6];

	data[0] = randChars();
	data[1] = randChars();
	data[2] = xorshift32();
	std::cout << data[2] << std::endl;
	data[3] = randChars();
	data[4] = randChars();
	data[5] = 0;

	return (data);
}

Data*	deserialize(void* raw)
{
	Data* d = new Data;

	int *i = reinterpret_cast<int *>(raw);

	d->n = i[2];
	i[2] = 0;

	d->s1 = reinterpret_cast<char *>(&i[0]);
	d->s2 = reinterpret_cast<char *>(&i[3]);

	return (d);
}

int main(void)
{
	Data* d = deserialize(serialize());

	std::cout << std::endl;
	std::cout << d->s1 << std::endl;
	std::cout << d->n << std::endl;
	std::cout << d->s2 << std::endl;

	std::cout << std::endl;

	Data* p = deserialize(serialize());

	std::cout << std::endl;
	std::cout << p->s1 << std::endl;
	std::cout << p->n << std::endl;
	std::cout << p->s2 << std::endl;

	return (0);
}
