#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include <limits>

class ScalarConverter {
public:
	static int  setPrecision(const std::string& input);
	static bool	isNumber(const std::string& input);
	static bool	isSpecialDouble(const std::string& input);
	static bool	isSpecial(const std::string& input);
	static void	double_to_other(const std::string& input);
	static void	char_to_other(const std::string& input);
	static void convert(const std::string& literal);
private:
	ScalarConverter& operator=(const ScalarConverter&);
	ScalarConverter(const ScalarConverter&);
	ScalarConverter();
	~ScalarConverter();
};

#endif