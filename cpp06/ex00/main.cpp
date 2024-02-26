#include "ScalarConverter.h"

int main(int ac, char **av) {
	
    if (ac != 2) {
        std::cout << "Usage: " << av[0] << " <string>" << std::endl;
        return 1;
    }
	ScalarConverter::convert(av[1]);
}