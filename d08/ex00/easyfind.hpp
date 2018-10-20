#ifndef EASYFIND_H
# define EASYFIND_H

template<typename T>
typename T::iterator	easyfind(T& haystack, int needle)
{
	typedef typename T::iterator TI;

	TI end = haystack.end();

	for (TI it = haystack.begin(); it != end; ++it)
	{
		if (*it == needle)
			return (it);
	}
	return (haystack.end());
}

#endif
