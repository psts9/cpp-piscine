#ifndef BRAIN_H
# define BRAIN_H

# include <string>

class Brain
{
public:
	Brain(void);
	Brain(int neurons, std::string currentThought);
	~Brain(void);

	int			getNeurons(void) const;

	std::string	identify(void) const;

private:
	int			neurons_;
	std::string	currentThought_;
};

#endif
