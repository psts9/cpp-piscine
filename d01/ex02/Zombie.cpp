#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(void) :
	name_("default"), type_("default")
{
	std::cout  <<
	"zombie <" << this->name_ << "> " <<
	"("		   << this->type_ << ") " <<
	"created!" <<
	std::endl;

	return;
}

Zombie::Zombie(std::string name, std::string type) :
	name_(name), type_(type)
{
	std::cout  <<
	"zombie <" << this->name_ << "> " <<
	"("		   << this->type_ << ") " <<
	"created!" <<
	std::endl;

	return;
}

Zombie::~Zombie(void)
{
	std::cout    <<
	"zombie <"   << this->name_ << "> " <<
	"("		     << this->type_ << ") " <<
	"destroyed!" <<
	std::endl;

	return;
}

void	Zombie::announce(void) const
{
	std::cout <<
	'<' << this->name_ << " (" << this->type_ << ")> " <<
	"Braiiiiiiinnnssss..."							   <<
	std::endl;

	return;
}
