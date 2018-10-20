#include <iostream>

# include "contact.hpp"

pb::contact::contact(void)
{
	return;
}

pb::contact::contact(std::string i_data[prompt_count])
{
	for (int i = 0; i < pb::prompt_count; ++i)
		this->data[i] = i_data[i];
	return;
}

pb::contact::~contact(void)
{
	return;
}

void		pb::contact::print(void)
{
	for (int i = 0; i < pb::prompt_count; ++i)
		std::cout << pb::contact_prompts[i] << ": "
				  << this->data[i] <<
		std::endl;
	return;
}

std::string pb::contact::first_name(void)
{
	return (this->data[0]);
}

std::string pb::contact::last_name(void)
{
	return (this->data[1]);
}

std::string pb::contact::nickname(void)
{
	return (this->data[2]);
}

std::string pb::contact::login(void)
{
	return (this->data[3]);
}

std::string pb::contact::postal_address(void)
{
	return (this->data[4]);
}

std::string pb::contact::email_address(void)
{
	return (this->data[5]);
}

std::string pb::contact::phone_number(void)
{
	return (this->data[6]);
}

std::string pb::contact::birthday(void)
{
	return (this->data[7]);
}

std::string pb::contact::favorite_meal(void)
{
	return (this->data[8]);
}

std::string pb::contact::underwear_color(void)
{
	return (this->data[9]);
}

std::string pb::contact::darkest_secret(void)
{
	return (this->data[10]);
}
