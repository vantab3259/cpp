#include "BitcoinExchange.h"

int main (int ac, char **av)
{
	
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <fichier.txt>" << std::endl;
		return 1;
	}
	BitcoinExchange btc(av[1]);
}