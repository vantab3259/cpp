#include <iostream>
int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptrstr = &str;
	std::string &refstr = str;

	std::cout << "Adresse de la string en mémoire : " << &str << std::endl;
    std::cout << "Adresse stockée dans stringPTR : " << ptrstr << std::endl;
    std::cout << "Adresse stockée dans stringREF : " << &refstr << std::endl;
    std::cout << "Valeur de la string : " << str << std::endl;
    std::cout << "Valeur pointée par stringPTR : " << *ptrstr << std::endl;
    std::cout << "Valeur pointée par stringREF : " << refstr << std::endl;
}