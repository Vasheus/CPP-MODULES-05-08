#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <stdexcept>
#include <algorithm>


template <typename T>
typename T::iterator easyfind(T &container, int i)
{
	typename T::iterator	iterate;
	iterate = find(container.begin(), container.end(), i);
	if (iterate == container.end())
	{
		throw std::out_of_range("index out of range");
	}
	return (iterate);
}

#endif