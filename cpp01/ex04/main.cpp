#include "replace.hpp"

int main(int ac, char **av)
{
	std::string file_replace;
	if(ac < 3 || !av[1][0] || !av[2][0] || !av[3][0])
	{
		std::cout << "wrong input" << std::endl;
		return(0);
	}
	file_replace = av[1];
	file_replace += ".replace";
	std::ofstream file2(file_replace.c_str());
	if(file2)
	{
		std::string after = replace(av[1], av[2], av[3]);
		file2 << after << std::endl;
	}
	return (0);
}