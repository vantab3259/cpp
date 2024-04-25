#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " 'nb nb op...' " << std::endl;
		return 1;
	}
	RPN Rpn(av[1]);	
}