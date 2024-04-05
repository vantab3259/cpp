
#include "whatever.h"


int main(void){
	std::string str = "un deux trois quatre cinq six sept huit neuf dix";

	std::string array[10];
	std::istringstream iss(str);
	size_t i = 0;
    while (iss >> array[i] && i < 10) 
        ++i;
    iter(array, 10, print);
}