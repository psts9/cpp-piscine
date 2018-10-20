#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie
{
public:
	Zombie(std::string name, std::string type);
	~Zombie(void);

	void	announce(void) const;

private:
	Zombie(void);

	const std::string	name_;
	const std::string	type_;
};

#endif
