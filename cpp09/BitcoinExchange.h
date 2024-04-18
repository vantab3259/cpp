#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(std::string const & inputFile);
    BitcoinExchange(BitcoinExchange const & copy);
	BitcoinExchange & operator=(BitcoinExchange const & copy);
    ~BitcoinExchange();
	bool 	isnum(const std::string& str, char type);
	bool	verifLine(std::string line, char type, bool csv);
	void	getCsvAndParsingFile();
	void	parsingFile(std::map<std::string, double> csvMap);
	std::string	getDate(std::string, char type, bool csv);
	double	getAmount(std::string, char type, bool csv);
	char	getTypeCsv(std::string str);
	class AmountOutOfRangeInCsv : public std::exception {
    	virtual const char* what() const throw(){
        	return ("too large a number in csv");
		}
    };
	class invalidFile : public std::exception  {
		virtual const char *what() const throw(){
			return("error file");
		}
	};
	class invalidCSV : public std::exception  {
		virtual const char *what() const throw(){
			return("error CSV");
		}
	};

private:
	std::string _inputFile;
};

#endif