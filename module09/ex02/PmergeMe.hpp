#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <stdexcept>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// ----- Class -----
class PmergeMe
{
    public:
        // ----- constructor -----
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
        ~PmergeMe();

        // ----- member functions -----
        void parseInput(int argc, char **argv);
        void mergeInsertSort();
        void displayResults(double timeVector, double timeDeque);

    private:
        void mergeInsertSortVector();
        void mergeInsertSortDeque();
        std::vector<size_t> generateGroupSizes(size_t n);

        std::vector<int> _vector;
        std::deque<int> _deque;
        std::vector<size_t> _groupSizes;
};

#endif
