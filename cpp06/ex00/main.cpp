#include "ScalarConverter.h"

int main(int ac, char **av) {
	
    const double d = std::numeric_limits<double>::infinity();

    std::cout<<"the value of a is\t"<<d << std::endl;

    if (ac != 2) {
        std::cout << "Usage: " << av[0] << " <string>" << std::endl;
        return 1;
    }
	ScalarConverter::convert(av[1]);
}