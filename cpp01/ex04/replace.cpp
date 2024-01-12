#include "replace.hpp"
#include <sys/types.h>
#include <sys/stat.h>

bool isRegularFile(const char *path)
{
    struct stat fileStat;
    if (stat(path, &fileStat) != 0)
        return false; // Error in stat

    return S_ISREG(fileStat.st_mode);
}

std::string replace(std::string file_name, std::string s1, std::string s2){
	std::ifstream inputFile(file_name.c_str());
	std::string previus_content;
	std::string line;
	while (std::getline(inputFile, line))
		previus_content += line + "\n";
	if(previus_content.empty())
		return(NULL);
	if(!s1[0])
	{
		previus_content.erase(previus_content.size() - 1);
		return(previus_content);
	}
	std::string content = "";
	size_t		pos = previus_content.find(s1);
	while (pos != std::string::npos)
	{
		content += previus_content.substr(0, pos);
		content += s2;
		previus_content.erase(0, pos + s1.length());
		pos = previus_content.find(s1);
	}
	content += previus_content;
	content.erase(content.size() - 1);
	std::cout << content;
	return(content);

}