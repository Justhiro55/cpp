#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <limits>
#include <map>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// macros
/// White space
#define WHITE_SPACE " \t\r\n\v\f"

/// Error message
#define ERROR_OPEN_FILE "Error: could not open file"
#define ERROR_INVALID_HEADER "Error: invalid header"
#define ERROR_INVALID_PARAMETER "Error: Invalid Parameter"
#define ERROR_BAD_INPUT "Error: bad input => "
#define ERROR_NOT_POSITIVE "Error: not a positive number."
#define ERROR_TOO_LARGE "Error: too large a number."
#define ERROR_INVALID_DATE_FORMAT "Error: invalid date format."
#define ERROR_INVALID_YEAR "Error: invalid year."
#define ERROR_INVALID_MONTH "Error: invalid month."
#define ERROR_INVALID_DATE "Error: invalid date."

// ----- Class -----
class BitcoinExchange
{
    public:
        // ----- constructor -----
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        ~BitcoinExchange();

        // ----- member functions -----
        void readData(std::string inputFile);
        void setData(std::string date, double value);
        double getData(const std::string& date);
        void printData();

    private:
    	std::map <std::string, double> _data;
};

#endif
