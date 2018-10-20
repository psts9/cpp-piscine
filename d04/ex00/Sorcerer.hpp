#ifndef SORCERER_H
# define SORCERER_H

# include <string>

# include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string const& name, std::string const& title);
	Sorcerer(Sorcerer const& sorcerer);
	~Sorcerer(void);

	Sorcerer& operator=(Sorcerer const& sorcerer);

	std::string getName(void) const;
	std::string	getTitle(void) const;

	void	polymorph(Victim const& victim) const;

private:
	Sorcerer(void);

	std::string	name_;
	std::string	title_;
};

std::ostream& operator<<(std::ostream& o, Sorcerer const& sorcerer);

#endif
