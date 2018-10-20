#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits.h>

#include "phonebook.hpp"

pb::phonebook::phonebook(void)
{
	this->index = 0;
	return;
}

pb::phonebook::~phonebook(void)
{
	return;
}

void		pb::phonebook::add(void)
{
	std::string input[pb::prompt_count];
	pb::contact	cont;

	if (this->index == pb::max_contacts)
	{
		std::cout << "Maximum number of contacts reached! Cannot add more!" << std::endl;
		return;
	}
	std::cin.ignore(INT_MAX, '\n');
	for (int i = 0; i < pb::prompt_count; ++i)
	{
		std::cout << pb::contact_prompts[i] << ": ";
		std::getline(std::cin, input[i]);
	}

	cont = pb::contact(input);
	this->contacts[this->index] = cont;
	++this->index;

	std::cout << "USER ADDED TO PHONEBOOK" << std::endl;

	return;
}

std::string	truncate(std::string s)
{
	int length;

	length = s.length();
	s = s.substr(0, 10);
	if (length > 10)
		s[9] = '.';
	return (s);
}

void		pb::phonebook::print_basic(void)
{
	int length = this->index;

	std::string first_name;
	std::string last_name;
	std::string nickname;

	std::cout << "     Index|First name| Last name|  Nickname" << std::endl;

	for (int i = 0; i < length; ++i)
	{
		first_name = truncate(this->contacts[i].first_name());
		last_name  = truncate(this->contacts[i].last_name());
		nickname   = truncate(this->contacts[i].nickname());

		std::cout << std::setw(10) << i <<
			  "|" << std::setw(10) << first_name <<
			  "|" << std::setw(10) << last_name	 <<
			  "|" << std::setw(10) << nickname	 <<
		std::endl;
	}

	return;
}

void		pb::phonebook::print_contact(int index)
{
	this->contacts[index].print();
}

void		pb::phonebook::search(void)
{
	std::string line;
	int			index;

	this->print_basic();

	std::cout << "Input the index of a contact: " << std::endl;
	std::cin.ignore(INT_MAX, '\n');
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> index)
		{
			if (ss.eof())
				break;
		}
		std::cout << "Please enter a valid number!" << std::endl;
	}

	if (index < 0 || index >= this->index)
	{
		std::cout << "That contact does not exist!" << std::endl;
		return;
	}

	this->print_contact(index);

	return;
}
