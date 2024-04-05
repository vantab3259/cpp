#include "ScalarConverter.h"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &source) {
	(void) source;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source) {
	(void) source;
	return *this;
}

bool	ScalarConverter::isNumber(const std::string& input) {
	bool hasDecimalPoint = false;
	bool hasF = false;

	for (size_t i = 0; i < input.size(); ++i) {
		char c = input[i];
		if (!std::isdigit(c)) {
			if (c == '.' && !hasDecimalPoint) {
				hasDecimalPoint = true;
			} else if (c == 'f' && !hasF) {
				hasF = true;
			} else if (i == 0 && input[i] == '-'){
				continue; // Un caractère invalide a été trouvé
			} else 
			 	return false;
		}
	}
	return true;
}



int ScalarConverter::setPrecision(const std::string& input) {

	size_t decimalPointIndex = input.find('.');
	int precision = 0;
    if (decimalPointIndex != std::string::npos) {
        size_t i = input.size() - 1;
        while (i > decimalPointIndex && input[i] == '0') 
            --i;
        if (i > decimalPointIndex) {
            --i;
			precision++;
        }
    }
    return precision;
}

bool	ScalarConverter::isSpecialDouble(const std::string& input) {
	return input == "inf" || input == "-inf" || input == "+inf" || input == "nan";
}

bool	ScalarConverter::isSpecial(const std::string& input) {
	return isSpecialDouble(input) || input == "inff" || input == "-inff" || input == "+inff" || input == "nanf";
}


void	ScalarConverter::double_to_other(const std::string& input)
{
	int prec = setPrecision(input);
	prec = prec == 0 ? 1 : prec;
	std::stringstream ss(input);
    double	doubleValue;
    float	floatValue;
	int		intValue;

	ss >> intValue;
	if (intValue > 255 || intValue < 0 || ss.fail() || !isNumber(input)) 
		std::cout << "char: : impossible"  << std::endl;
	else if(!isprint(intValue) || intValue == 0)
		std::cout << "char: Non displayable" << std::endl;
	else 
		std::cout << "char: " << static_cast<char>(intValue) << std::endl;
	ss.clear();
	ss.seekg(0, std::ios::beg);

	ss >> intValue;
	if (ss.fail() || !isNumber(input)) {
		std::cout << "int: : impossible"  << std::endl;
    } else {
        std::cout << "int: " <<static_cast<int>(intValue) << std::endl;
	}
	ss.clear();
    ss.seekg(0, std::ios::beg);

	ss >> floatValue;
	if (ss.fail() || !isNumber(input)) {
		std::cout << "float: : impossible"  << std::endl;
    } else {
        std::cout << "float: " << std::fixed << std::setprecision(prec) <<static_cast<float>(floatValue) << "f" << std::endl;
	}
	ss.clear();
    ss.seekg(0, std::ios::beg);

    ss >> doubleValue;
    if (ss.fail() || !isNumber(input)) {
		std::cout << "double: : impossible"  << std::endl;
    } else {
        std::cout << "double: " << std::fixed << std::setprecision(prec) <<static_cast<double>(doubleValue) << std::endl;
	}
}

void	ScalarConverter::char_to_other(const std::string& input)
{
	if(!isprint(input[1]))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: "  << input[1] << std::endl;
	std::cout << "int: "<< static_cast<int>(input[1]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[1])  << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) <<static_cast<double>(input[1]) << std::endl;
}


void	ScalarConverter::convert(const std::string& input)
{
	if(input.size() == 3 && input[0] == '\'' && isprint(input[1]) && input[2] == '\'')
		char_to_other(input);
	else
    {
		if (isSpecial(input)) 
		{
			std::cout << "char  : impossible" << std::endl;
			std::cout << "int   : impossible" << std::endl;
			std::cout << "float : " << input + (isSpecialDouble(input) ? "f" : "") << std::endl;
			std::cout << "double: " << input << std::endl;
    	}
		else
			double_to_other(input);
	}
}