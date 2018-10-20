#ifndef CONTACT_H
# define CONTACT_H

# include <string.h>

namespace pb
{

const int	prompt_count = 11;

const std::string contact_prompts[prompt_count] =
{
		"First name",
		"Last name",
		"Nickname",
		"Login",
		"Postal address",
		"Email address",
		"Phone number",
		"Birthday",
		"Favorite meal",
		"Underwear color",
		"Darkest secret"
};

class contact
{
public:
	contact(void);
	contact(std::string data[prompt_count]);
	~contact(void);

	void print(void);

	std::string first_name(void);
	std::string last_name(void);
	std::string nickname(void);
	std::string login(void);
	std::string postal_address(void);
	std::string email_address(void);
	std::string phone_number(void);
	std::string birthday(void);
	std::string favorite_meal(void);
	std::string underwear_color(void);
	std::string darkest_secret(void);

private:
	std::string	data[prompt_count];
};

}

#endif
