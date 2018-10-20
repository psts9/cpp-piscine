#include <sstream>

#include "Brain.hpp"

Brain::Brain(void) : neurons_(0), currentThought_("nothing")
{
	return;
}

Brain::Brain(int neurons, std::string currentThought) :
	neurons_(neurons), currentThought_(currentThought)
{
	return;
}

Brain::~Brain(void)
{
	return;
}

std::string Brain::identify(void) const
{
	std::stringstream memoryAddress;

	memoryAddress << this;

	return (memoryAddress.str());
}

int			Brain::getNeurons(void) const
{
	return (this->neurons_);
}
