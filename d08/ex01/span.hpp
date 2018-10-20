#ifndef SPAN_H
# define SPAN_H

# include <exception>
# include <vector>

class Span
{
public:
	Span(void);
	Span(unsigned int size);
	Span(Span const& span);
	~Span(void);

	Span& operator=(Span const& span);

	void	addNumber(int n);
	void	addNumber(std::vector<int>::iterator it, std::vector<int>::iterator end);

	int		shortestSpan(void) const;
	int		longestSpan(void) const;

private:
	class	AddingToFullSpanException : public std::exception
	{
	public:
		AddingToFullSpanException(void);
		AddingToFullSpanException(AddingToFullSpanException const& e);
		~AddingToFullSpanException(void) _NOEXCEPT;

		virtual const char* what(void) const throw();

	private:
		AddingToFullSpanException& operator=(AddingToFullSpanException const& e);

	};

	class	TooFewNumberToFindSpanException : public std::exception
	{
	public:
		TooFewNumberToFindSpanException(void);
		TooFewNumberToFindSpanException(TooFewNumberToFindSpanException const& e);
		~TooFewNumberToFindSpanException(void) _NOEXCEPT;

		virtual const char* what(void) const throw();

	private:
		TooFewNumberToFindSpanException& operator=(TooFewNumberToFindSpanException);

	};

private:
	std::vector<int>	arr_;
	unsigned int		size_;
	unsigned int		currIndex_;
};

#endif
