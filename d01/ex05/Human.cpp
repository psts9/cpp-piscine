#include "Human.hpp"

Human::Human(void) : age_(0), name_("default")
{
	return;
}

Human::Human(int age, std::string name) : age_(age), name_(name)
{
	return;
}

Human::~Human(void)
{
	return;
}

int			 Human::getAge(void) const
{
	return (this->age_);
}

Brain const& Human::getBrain(void) const
{
	return (this->brain_);
}

std::string	 Human::getName(void) const
{
	return (this->name_);
}

std::string	 Human::identify(void) const
{
	return (this->brain_.identify());
}
