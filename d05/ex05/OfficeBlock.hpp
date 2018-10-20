#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock
{
public:
	OfficeBlock(void);
	OfficeBlock(Intern* intern, Bureaucrat* signer, Bureaucrat* executer);
	~OfficeBlock(void);

	void	setIntern(Intern* intern);
	void	setSigner(Bureaucrat* signer);
	void	setExecuter(Bureaucrat* executer);

	void	doBureaucracy(std::string const& type, std::string const& target);

private:
	OfficeBlock(OfficeBlock const& ob);

	OfficeBlock& operator=(OfficeBlock const& ob);

private:
	class NoInternException : public std::exception
	{
	public:
		NoInternException(void);
		NoInternException(NoInternException const& e);
		~NoInternException(void) _NOEXCEPT;

		NoInternException& operator=(NoInternException const& e);

	public:
		virtual const char* what(void) const throw();
	};

	class NoSigningBureaucratException : public std::exception
	{
	public:
		NoSigningBureaucratException(void);
		NoSigningBureaucratException(NoSigningBureaucratException const& e);
		~NoSigningBureaucratException(void) _NOEXCEPT;

		NoSigningBureaucratException& operator=(NoSigningBureaucratException const& e);

	public:
		virtual const char* what(void) const throw();
	};

	class NoExecutingBureaucratException : public std::exception
	{
	public:
		NoExecutingBureaucratException(void);
		NoExecutingBureaucratException(NoExecutingBureaucratException const& e);
		~NoExecutingBureaucratException(void) _NOEXCEPT;

		NoExecutingBureaucratException& operator=(NoExecutingBureaucratException const& e);

	public:
		virtual const char* what(void) const throw();
	};

private:
	Intern* intern_;
	Bureaucrat* signer_;
	Bureaucrat* executer_;
};

#endif
