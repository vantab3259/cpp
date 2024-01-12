
#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>

std::string replace(std::string file_name, std::string s1, std::string s2);

bool isRegularFile(const char *path);
#endif