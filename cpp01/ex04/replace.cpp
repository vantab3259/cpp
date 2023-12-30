#include "replace.hpp"

std::string replace(std::string file_name, std::string s1, std::string s2){
	
	std::ifstream inputFile(file_name.c_str());
	if (inputFile.is_open())
	{
		std::string previus_content;
		std::string line;
		while (std::getline(inputFile, line)) {
           previus_content += line;
           previus_content += "\n";
        }
		if(previus_content.empty()){
			std::cout << " Empty file" << std::endl;
			return("");
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
		return(content);
	}
	else
		std::cout << "file error" << std::endl;
	return("");
}