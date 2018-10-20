#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(std::string const& target);
	~RobotomyRequestForm(void);

	RobotomyRequestForm& operator=(RobotomyRequestForm const& form);

	void	execute(Bureaucrat const& bureaucrat) const;

private:
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const& form);

private:
	void executeRobotomyRequestForm(void) const;

private:
	std::string const target_;
};

#endif
