#include <cstdlib>
#include <limits.h>
#include <cmath>

#include "span.hpp"

//~--------------------------------------------------------~
// Constructors & Destructor

Span::Span(void) : size_(0), currIndex_(0)
{
	return;
}

Span::Span(unsigned int size) : size_(size), currIndex_(0)
{
	return;
}

Span::Span(Span const& span)
{
	*this = span;

	return;
}

Span::~Span(void)
{
	return;
}

//~--------------------------------------------------------~
// Operators

Span&	Span::operator=(Span const& span)
{
	arr_  		= span.arr_;
	size_		= span.size_;
	currIndex_  = span.currIndex_;

	return (*this);
}

//~--------------------------------------------------------~
// Exceptions

Span::AddingToFullSpanException::AddingToFullSpanException(void)
{
	return;
}

Span::AddingToFullSpanException::~AddingToFullSpanException(void) _NOEXCEPT
{
	return;
}

const char* Span::AddingToFullSpanException::what(void) const throw()
{
	return ("Trying to add number to full span class");
}

Span::TooFewNumberToFindSpanException::TooFewNumberToFindSpanException(void)
{
	return;
}

Span::TooFewNumberToFindSpanException::~TooFewNumberToFindSpanException(void) _NOEXCEPT
{
	return;
}

const char* Span::TooFewNumberToFindSpanException::what(void) const throw()
{
	return ("Too few numbers to find span");
}

//~--------------------------------------------------------~
// Functions

void	Span::addNumber(int n)
{
	if (currIndex_ >= size_)
		throw(AddingToFullSpanException());

	arr_.push_back(n);
	++currIndex_;

	return;
}

void	Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator end)
{
	std::vector<int> temp(it, end);

	if (temp.size() + currIndex_ >= size_)
		throw(AddingToFullSpanException());

	end = temp.end();
	for (it = temp.begin(); it != end; ++it)
		arr_.push_back(*it);

	currIndex_ += temp.size();

	return;
}

int		Span::shortestSpan(void) const
{
	if (currIndex_ < 2)
		throw(TooFewNumberToFindSpanException());

	int min;
	int temp;

	min = INT_MAX;
	for (unsigned int i = 0; i < currIndex_ - 1; ++i)
	{
		for (unsigned int j = i + 1; j < currIndex_; ++j)
		{
			temp = fabs(arr_[i] - arr_[j]);
			if (temp < min)
				min = temp;
		}
	}
	return (min);
}

int		Span::longestSpan(void) const
{
	if (currIndex_ < 2)
		throw(TooFewNumberToFindSpanException());

	int min = INT_MAX;
	int max = 0;

	for (unsigned int i = 0; i < currIndex_; ++i)
	{
		int temp = arr_[i];

		if (temp < min)
			min = temp;
		if (temp > max)
			max = temp;
	}

	return (fabs(min - max));
}
