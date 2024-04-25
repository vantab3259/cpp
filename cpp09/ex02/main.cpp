#include "PmergeMe.h"

int main (int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Usage: " << av[0] << "numbers : 3 5 63 3 64 52 6 4 3 " << std::endl;
		return 1;
	}

	PmergeMe p(av);
	
}