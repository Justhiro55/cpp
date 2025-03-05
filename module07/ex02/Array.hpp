#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cmath>
#include <cctype>
#include <sstream>
#include <climits>
#include <stdexcept>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

template<typename T> class Array{
    public:
        // ----- orthodox canonical form -----
        Array();
        Array(const unsigned int n);
        Array(const Array &obj);
        Array &operator=(const Array &obj);
        ~Array();

        // ----- member functions -----
        T &operator[](const unsigned int i);
        const T &operator[](const unsigned int i) const;
        unsigned int size() const;

        // ----- helper functions -----
        void printArray() const;

    private:
        // ----- member variables -----
        T *m_array;
        unsigned int m_n;
};

#include "Array.tpp"

#endif
