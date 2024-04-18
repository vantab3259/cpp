#include "BitcoinExchange.h"


bool	print_err(std::string const & err){
	std::cout << "error: " << err << std::endl;
	return false;
}

bool BitcoinExchange::isnum(const std::string& str, char type) {
	int space = 0,point = 0, tp = 0;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isdigit(*it) && *it != '-' && *it != type && *it != '.' && *it != ' ') 
            return print_err("Error: bad input => " + str);
		if(*it == type)
		 	tp = tp+1;
		if(*it == '.')
		 	point++;
		if(*it == ' ')
		{
			space++;
			if ((!isdigit(*(it-1)) && *(it+1) != '|') && (!isdigit(*(it+1)) && *(it-1) != '|'))
            	return print_err("Error: bad input => " + str);
		}
    }
	if(( space != 2 && space != 0) || point > 1 ||  tp != 1)
		return print_err("Error: bad input => " + str);
	if(!isdigit(str[str.size()-1]) || !isdigit(str[0]))
		return print_err("Error: bad input => " + str);
    return true;
}

bool	BitcoinExchange::verifLine(std::string line, char type, bool csv)
{
	std::string strPro = "date" + std::string(1, type) + "exchange_rate";
	if (line == strPro && csv)
		return true;
	if (!isnum(line, type))
	{
		std::cout <<"lalsldllfl";
		return false;
	}
	std::stringstream ss(line);
	int year, month, day;
	double amount;
	char delim1, delim2, delim3;

	ss >> year  >> delim1 >> month >> delim2 >> day >> delim3 >>  amount; 

	if (delim1 != '-' || delim2 != '-' || delim3 != type)
		return print_err("Error: bad input => " + line);
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return print_err("Error: bad input => " + line);
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return print_err("Error: bad input => " + line);
	}
	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
			return print_err("Error: bad input => " + line);
		}
	}
	if ((amount < 0 || amount > 1000) && !csv)
    	return print_err(amount > 1000 ? "Error: too large a number." : "Error: too small a number.");
	if ((amount < 0 || amount > 9999999) && csv)
    	return print_err(amount > 9999999 ? "Error: too large a number." : "Error: too small a number.");
	return true;
}

void	BitcoinExchange::parsingFile(std::map<std::string, double> csvMap)
{
	double amount;
	std::string date;
	std::ifstream i(_inputFile.c_str());
	if(!i.is_open()){
		throw invalidFile();
	}
	std::string line;
	std::map<std::string, double> fileMap;
	while(std::getline(i, line))
	{
		if(verifLine(line, '|', false))
		{

			amount = getAmount(line, '|', false);
			if(amount == -1)
				std::cout << "ERROR : too large a number" << std::endl;
			date = getDate(line, '|', false);
			bool found = false;
			for( std::map<std::string, double>::iterator it = csvMap.begin(); it != csvMap.end(); it++)
			{
				if(it->first == date)
				{
					found = true;
					std::cout << date << "--> " << amount * it->second << std::endl; 
					break;
				}
				if(it->first > date){
 					if (it == ++csvMap.begin()){
						found = true;
						std::cout << "No information yet, to early date" << std::endl;
					}
					if (it != ++csvMap.begin()) {
                		--it;
                		std::cout << date << "--> " << amount * it->second << std::endl;
						found = true;
            		} 
            		break;
				}
			}
			if(found == false)
                std::cout << date << "--> " << amount * (--csvMap.end()->second)<< std::endl;
		}
	}
}

void	BitcoinExchange::getCsvAndParsingFile()
{
	char type;
	int first = 0;
	std::ifstream d("data.csv");
	if(!d.is_open()){
		throw invalidCSV();
	}
	std::string line;
	std::map<std::string, double> csvMap;
	while(std::getline(d, line))
	{
		if(first == 0 ){
			type = getTypeCsv(line);
			first = 1;
		}
		if(!verifLine(line, type, true))
			throw invalidCSV();
		csvMap[getDate(line, type, true)] = getAmount(line, type, true);
	}
	parsingFile(csvMap);
}

char	BitcoinExchange::getTypeCsv(std::string str)
{
	std::map<int, char> sepPoss;
	
	sepPoss[0] = ',';
    sepPoss[1] = ';';
    sepPoss[2] = '|';
    sepPoss[3] = ' ';
    sepPoss[4] = '\t';
    sepPoss[5] = ':';
	for(std::map<int, char>::iterator it = sepPoss.begin();it != sepPoss.end(); it++)
	{
		if(str.find(it->second)!= std::string::npos)
			return(it->second);
	}
    return '\0';
}
 

std::string	BitcoinExchange::getDate(std::string str, char type, bool csv){
	std::string strPro = "date" + std::string(1, type) + "exchange_rate";
	if (strPro == str && csv)
		return "";
	size_t pos = str.find(type);
	std::string substr= str.substr(0, pos);
	return( substr );
}

double	BitcoinExchange::getAmount(std::string str, char type, bool csv){
	std::string strPro = "date" + std::string(1, type) + "exchange_rate";
	if (strPro == str && csv)
		return 0;
	size_t pos = str.find(type);
	size_t nnpos = str.find('.');

	if(nnpos != str.npos && (nnpos - pos > 8 && csv))
		throw AmountOutOfRangeInCsv();
	if(nnpos != str.npos && (nnpos - pos > 8 && !csv))
		return -1;
	std::stringstream ss(str.substr(pos+1));
	float f;
	ss >> f;
	return( f );
}

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(std::string const & file) : _inputFile(file)
{
	try{
		getCsvAndParsingFile();
	}
	catch(std::exception & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & copy)
{
	*this = copy;
	return ;

}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & copy)
{
	(void) copy;
	return (*this);

}


BitcoinExchange::~BitcoinExchange()
{

}