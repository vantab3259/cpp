#include "replace.hpp"

int main(int ac, char **av)
{
	std::string file_replace;
	if(ac != 4 )
    {
        std::cout << "wrong input" << std::endl;
        return (1);
    }
	std::cout << isRegularFile(av[1]) << std::endl;
	if (!isRegularFile(av[1]))
	{
        std::cout << "wrong file" << std::endl;
        return (1);
    }
	std::ifstream inputFile(av[1]);
	file_replace = std::string(av[1]) + ".replace";
	std::ofstream file2(file_replace.c_str());
	if(file2)
	{
		std::string after = replace(av[1], av[2], av[3]);
		file2 << after;
	}
	if(inputFile.is_open())
		inputFile.close();
	if (file2.is_open()) 
        file2.close();
	return (0);
}