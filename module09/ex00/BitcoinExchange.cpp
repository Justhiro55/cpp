#include "BitcoinExchange.hpp"

void isValidDate(const std::string& date);
void isValidValue(const double value);
std::string trim(const std::string& str);
bool containsInvalidChars(const std::string& str);

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << RED << ERROR_OPEN_FILE << RESET << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // for skipping the header line
    if (line != "date,exchange_rate")
    {
        std::cerr << ERROR_INVALID_HEADER << RESET << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        line = trim(line);
        if(line.empty() || containsInvalidChars(line))
            continue;
        size_t pos = line.find(',');
        if (pos == std::string::npos)
        {
            std::cerr << ERROR_INVALID_PARAMETER << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, pos));
        double value;
        try {
            std::istringstream iss(line.substr(pos + 1));
            if (!(iss >> value))
                throw std::runtime_error("Error: failed to convert to double");
            this->setData(date, value);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
    }
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
    if (this != &obj)
    {
        this->_data = obj._data;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
    if (this != &obj)
        *this = obj;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readData(std::string inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        std::cerr << RED << ERROR_OPEN_FILE << RESET << std::endl;
        return;
    }

    std::string line;
    if (!std::getline(file, line) || trim(line) != "date | value")
    {
        std::cerr << RED << ERROR_INVALID_HEADER << RESET << std::endl;
        return;
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        line = trim(line);
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << ERROR_BAD_INPUT << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        date = trim(date);
        std::string valueStr = line.substr(pos + 1);
        valueStr = trim(valueStr);
        if ( date.empty() || valueStr.empty() )
            continue;
        else if ( containsInvalidChars(date) || containsInvalidChars(valueStr) )
        {
            std::cerr << ERROR_BAD_INPUT << line << std::endl;
            continue;
        }

        double value;
        try {
            std::istringstream iss(valueStr);
            if (!(iss >> value))
                throw std::runtime_error("Error: failed to convert to double");
        } catch (std::exception &e) {
            std::cerr << ERROR_BAD_INPUT << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << ERROR_NOT_POSITIVE << std::endl;
            continue;
        }
        else if (value > 1000)
        {
            std::cerr << ERROR_TOO_LARGE << std::endl;
            continue;
        }

        try {
            isValidDate(date);

            double rate = getData(date);
            double btcValue = value * rate;

            std::cout << date << " => " << value << " = " << btcValue << std::endl;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
    }
}

double BitcoinExchange::getData(const std::string& date)
{
    std::map<std::string, double>::iterator it = _data.find(date);

    if (it != _data.end())
        return it->second;

    it = _data.lower_bound(date);

    if (it == _data.begin())
        throw std::runtime_error("Error: no data available for this date.");

    --it;
    return it->second;
}

void BitcoinExchange::setData(std::string date, double value)
{
    // Check if the date is valid
    isValidDate(date);

    // Check if the value is a valid
    isValidValue(value);

    this->_data.insert(std::make_pair(date, value));
}

// ------ Helper Functions ------
void isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::invalid_argument(ERROR_INVALID_DATE_FORMAT);

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            throw std::invalid_argument(ERROR_INVALID_DATE_FORMAT);
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    int y = std::atoi(year.c_str());
    int m = std::atoi(month.c_str());
    int d = std::atoi(day.c_str());

    if (y < 2009 || y > 2025)
        throw std::invalid_argument(ERROR_INVALID_YEAR);
    else if (m < 1 || m > 12)
        throw std::invalid_argument(ERROR_INVALID_MONTH);

    int daysInMonth;

    if (m == 2) // うるう年
    {
        bool isLeapYear = false;
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            isLeapYear = true;
        if (isLeapYear)
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;

    if (d < 1 || d > daysInMonth)
        throw std::invalid_argument(ERROR_INVALID_DATE);
}

void isValidValue(const double value)
{
    if (value < 0)
        throw std::invalid_argument(ERROR_NOT_POSITIVE);
    else if (value > std::numeric_limits<int>::max())
        throw std::invalid_argument(ERROR_TOO_LARGE);
}

std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(WHITE_SPACE);
    size_t end = str.find_last_not_of(WHITE_SPACE);

    return start == std::string::npos ? "" : str.substr(start, end - start + 1);
}

bool containsInvalidChars(const std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-' && str[i] != ',' && str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
        {
            std::cerr << ERROR_BAD_INPUT << str << std::endl;
            return true;
        }
    }
    return false;
}

void BitcoinExchange::printData()
{
    for (std::map<std::string, double>::const_iterator ite = _data.begin(); ite != _data.end(); ++ite)
    {
        std::cout << ite->first << ": " << ite->second << std::endl;
    }
}
