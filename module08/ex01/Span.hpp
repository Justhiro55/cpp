#ifndef SPAN_HPP
#define SPAN_HPP

// ----- includes -----
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <sstream>
#include <climits>
#include <stdexcept>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// ----- class -----
class Span{
    public:
        // ----- orthodox canonical form -----
        Span();
        Span(const unsigned int n);
        Span(const Span &obj);
        Span &operator=(const Span &obj);
        ~Span();

        // ----- member functions -----
        void addNumber(const unsigned int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        template <typename Iterator>
        void addRange(Iterator begin, Iterator end);

        // ----- helper functions -----
        void printArray() const;

    private:
        // ----- member variables -----
        std::vector<unsigned int> _array;
        unsigned int _size;
        unsigned int _pos;
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        if (_pos >= _size)
            throw std::out_of_range("Array is full");
        addNumber(*begin);
        ++begin;
    }
}

#endif
