#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie
{
public:
	Zombie(void);
	Zombie(std::string name, std::string type);
	~Zombie(void);

	void	announce(void) const;

	void	setName(std::string name);
	void	setType(std::string type);

private:
	std::string	name_;
	std::string	type_;
};

#endif
