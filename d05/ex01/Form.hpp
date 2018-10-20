#ifndef FORM_H
# define FORM_H

# include <string>

class Bureaucrat;

class Form
{
public:
	Form(std::string const& name, unsigned short signGrade, unsigned short executeGrade);
	Form(Form const& form);
	~Form(void);

	Form& operator=(Form const& form);

public:
	std::string const&	getName(void) const;
	unsigned short		getSignGrade(void) const;
	unsigned short		getExecuteGrade(void) const;
	bool				getIsSigned(void) const;

	void	beSigned(Bureaucrat const& bureaucrat);

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
	Form(void);

private:
	std::string const	 name_;
	unsigned short const signGrade_;
	unsigned short const executeGrade_;
	bool isSigned_;
};

std::ostream& operator<<(std::ostream& o, Form const& form);

#endif
