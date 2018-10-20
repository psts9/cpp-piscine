#ifndef INTERN_H
# define INTERN_H

#include "Form.hpp"

class Intern
{
public:
	Intern(void);
	Intern(Intern& intern);
	~Intern(void);

	Intern& operator=(Intern& intern);

public:
	class InvalidFormTypeException : public std::exception
	{
	public:
		InvalidFormTypeException(void);
		InvalidFormTypeException(InvalidFormTypeException const& form);
		~InvalidFormTypeException(void) _NOEXCEPT;

		InvalidFormTypeException& operator=(InvalidFormTypeException const& e);

	public:
		virtual const char* what(void) const throw();
	};

public:
	Form*	makeForm(std::string const& type, std::string const& target);

};

#endif
