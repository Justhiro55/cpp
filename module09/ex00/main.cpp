#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED;
        std::cerr << "Error: wrong number of arguments" << std::endl;
        std::cerr << "Usage: " << av[0] << " <filename>" << std::endl << std::endl;
        return EXIT_FAILURE;
    }

    BitcoinExchange btc;
    btc.readData(av[1]);
    return EXIT_SUCCESS;
}
