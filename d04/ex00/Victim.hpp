#ifndef VICTIM_H
# define VICTIM_H

# include <string>

class Victim
{
public:
	Victim(std::string const& name);
	Victim(Victim const& victim);
	virtual ~Victim(void);

	Victim& operator=(Victim const& victim);

	std::string getName(void) const;

	virtual void getPolyMorphed(void) const;

protected:
	std::string name_;

private:
	Victim(void);
};

std::ostream& operator<<(std::ostream& o, Victim const& victim);

#endif
