#ifndef PONY_H
# define PONY_H

# include <string>

class Pony
{
public:
	Pony(int age, int legs, std::string description);
	~Pony(void);

	void		printInfo(void) const;

	int			getAge(void) const;
	int			getLegs(void) const;
	std::string	getDescription(void) const;

	void		neigh(void) const;

	void		setAge(int age);
	void		setLegs(int legs);
	void		setDescription(std::string description);

private:
	Pony(void);

	int			age_;
	int			legs_;
	std::string	description_;
};

#endif
