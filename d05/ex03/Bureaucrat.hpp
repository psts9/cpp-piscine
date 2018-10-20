#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>

class Form;

class Bureaucrat
{
public:
	Bureaucrat(std::string const& name, unsigned short grade);
	Bureaucrat(Bureaucrat const& bureaucrat);
	~Bureaucrat(void);

	Bureaucrat& operator=(Bureaucrat const& bureaucrat);

public:
	std::string	const&	getName(void) const;
	unsigned short		getGrade(void) const;

	void	incGrade(void);
	void	decGrade(void);

	void	signForm(Form& form);
	void	executeForm(Form const& form);

private:
	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(GradeTooHighException const& e);
		~GradeTooHighException(void) _NOEXCEPT;

		GradeTooHighException& operator=(GradeTooHighException const& e);

	public:
		virtual const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(void);
		GradeTooLowException(GradeTooLowException const& e);
		~GradeTooLowException(void) _NOEXCEPT;

		GradeTooLowException& operator=(GradeTooLowException const& e);

	public:
		virtual const char* what(void) const throw();
	};

private:
	Bureaucrat(void);

private:
	std::string const name_;
	unsigned short	  grade_;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& bureaucrat); 

#endif
