#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string const& target);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& form);

	void	execute(Bureaucrat const& bureaucrat) const;

private:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const& form);

private:
	void	executeShrubberyCreationForm(void) const;

private:
	std::string const target_;
};

#endif
