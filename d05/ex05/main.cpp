#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

#include "CentralBureaucracy.hpp"

std::string randName(void)
{
	std::string temp(rand() % 10 + 4, 'a');

	temp[0] = toupper(temp[0]);

	for (size_t i = 1; i < temp.length(); ++i)
	{
		temp[i] += (rand() % 26);
	}

	return (temp);
}

int main(void)
{
	srand(time(NULL));

	CentralBureaucracy cb;

	for (int i = 0; i < 20; ++i)
	{
		Bureaucrat* temp = new Bureaucrat(randName(), rand() % 150 + 1);
		cb.addBureaucrat(temp); 
	}

	for (int i = 0; i < 200; ++i)
	{
		cb.queueUp(randName());
	}

	cb.doBureaucracy();

	return (0);
}
