#ifndef HUMAN_H
# define HUMAN_H

# include "Brain.hpp"

class Human
{
public:
	Human(void);
	Human(int age, std::string name);
	~Human(void);

	int				getAge(void) const;
	std::string		getName(void) const;
	Brain const&	getBrain(void) const;

	std::string identify(void) const;

private:
	int			age_;
	const Brain	brain_;
	std::string	name_;
};

#endif
