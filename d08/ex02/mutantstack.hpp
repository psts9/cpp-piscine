#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <stack>
# include <deque>

template<typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
	using std::stack<T, C>::c;

public:
	typedef typename std::deque<T>::iterator iterator;

	MutantStack<T, C>(void) : std::stack<T, C>()
	{
		return;
	}

	MutantStack<T, C>(MutantStack<T, C> const& stack)
	{
		*this = stack;
	}

	~MutantStack<T, C>(void)
	{
		return;
	}

	typename std::deque<T>::iterator begin(void)
	{
		return (c.begin());
	}

	typename std::deque<T>::iterator end(void)
	{
		return (c.end());
	}

	MutantStack& operator=(MutantStack const& stack);
};

#endif
