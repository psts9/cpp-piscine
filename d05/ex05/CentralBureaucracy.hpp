#ifndef CENTRALBUREAUCRACY_H
# define CENTRALBUREAUCRACY_H

# include "OfficeBlock.hpp"

class CentralBureaucracy
{
public:
	CentralBureaucracy(void);
	~CentralBureaucracy(void);

	void	doBureaucracy(void);

	void	queueUp(std::string const& target);
	void	addBureaucrat(Bureaucrat* bureaucrat);

private:
	CentralBureaucracy(CentralBureaucracy const& cb);

	CentralBureaucracy& operator=(CentralBureaucracy const& cb);

private:
	class FullTargetQueueException : public std::exception
	{
	public:
		FullTargetQueueException(void);
		FullTargetQueueException(FullTargetQueueException const& e);
		~FullTargetQueueException(void) _NOEXCEPT;

		FullTargetQueueException& operator=(FullTargetQueueException const& e);

	public:
		virtual const char* what(void) const throw();
	};

	class FullBureaucratQueueException : public std::exception
	{
	public:
		FullBureaucratQueueException(void);
		FullBureaucratQueueException(FullBureaucratQueueException const& e);
		~FullBureaucratQueueException(void) _NOEXCEPT;

		FullBureaucratQueueException& operator=(FullBureaucratQueueException const& e);
	
	public:
		virtual const char* what(void) const throw();
	};

private:
	OfficeBlock officeBlocks_[20];
	Bureaucrat* bureaucrats_[40];

	std::string targetQueue_[512];

	int	officeBlockCount_;
	int	queueCounter_;
	int	bureaucratCount_;
};

#endif
