#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.hpp"

namespace pb 
{

const int	max_contacts = 8;

class phonebook
{
public:
	phonebook(void);
	~phonebook(void);

	void	add(void);
	void	search(void);
	void	print_basic(void);
	void	print_contact(int);

private:
	int		index;
	contact	contacts[max_contacts];
};

}

#endif
