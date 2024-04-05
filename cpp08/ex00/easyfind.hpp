#ifndef EASYFIND_H
# define EASYFIND_H
# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>

# define PINK "\e[0;38;5;199m"
# define LILAC "\e[0;38;5;13m"
# define PURPLE "\e[0;38;5;93m"
# define BOLD_RED "\e[1;31m"
# define BLUE "\e[0;34m"
# define V_CYAN "\e[0;38;5;44m"
# define RESET "\e[0m"

template <typename T>

typename T::const_iterator easyfind(const T &container, const int n)
{
	return std::find(container.begin(), container.end(),n);
}

#endif