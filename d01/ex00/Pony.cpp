#include <iostream>

#include "Pony.hpp"

void	Pony::printInfo(void) const
{
	std::cout	    <<
	"Age: "         << this->age_         << std::endl <<
	"Legs: "        << this->legs_        << std::endl <<
	"Description: " << this->description_ <<
	std::endl;
	
	return;
}

Pony::Pony(void) :
	age_(0), legs_(0), description_("Default")
{
	std::cout << "Horse created:" << std::endl;
	this->printInfo();
	std::cout << std::endl;
	return;
}

Pony::Pony(int age, int legs, std::string description) : 
	age_(age), legs_(legs), description_(description)
{
	std::cout << "Horse created:" << std::endl;
	this->printInfo();
	std::cout << std::endl;
	return;
}

Pony::~Pony(void)
{
	std::cout << "Horse deleted:" << std::endl;
	this->printInfo();
	std::cout << std::endl;
	return;
}

int		Pony::getAge(void) const
{
	return (this->age_);
}

int 	Pony::getLegs(void) const
{
	return (this->legs_);
}

std::string Pony::getDescription(void) const
{
	return (this->description_);
}

void	Pony::setAge(int age)
{
	this->age_ = age;
	return;
}

void	Pony::setLegs(int legs)
{
	this->legs_ = legs;
	return;
}

void	Pony::setDescription(std::string description)
{
	this->description_ = description;
	return;
}

void	Pony::neigh(void) const
{
	std::cout << this->description_ << " says: " << "Neigh!" << std::endl;

	return;
}
