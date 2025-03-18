#include "Span.hpp"

int main()
{
    std::cout << std::endl;

    Span sp = Span(5);
    std::cout << CYAN << "----- Span test -----" << RESET << std::endl;
    try
    {
        sp.addNumber(5);
        sp.addNumber(4);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    std::cout << CYAN << "----- member function test -----" << RESET << std::endl;
    try
    {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << std::endl;
    std::cout << CYAN << "----- addRange test -----" << RESET << std::endl;
    try
    {
        Span sp2 = Span(10000);
        std::vector<unsigned int> v;

        for (unsigned int i = 0; i < 10000; i++)
            v.push_back(i);

        sp2.addRange(v.begin(), v.end());
        std::cout << "Added 10,000 numbers using addRange" << std::endl;
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
