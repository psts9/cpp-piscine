#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string const& target);
	~PresidentialPardonForm(void);

	PresidentialPardonForm& operator=(PresidentialPardonForm const& form);

	void execute(Bureaucrat const& bureaucrat) const;

private:
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const& form);

private:
	void	executePresidentialPardonForm(void) const;

private:
	std::string const target_;	
};

#endif
