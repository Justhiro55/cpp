#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <cmath>
#include <map>
#include <cctype>
#include <sstream>
#include <climits>
#include <stdexcept>
#include <vector>
#include <deque>
#include <list>
#include <fstream>
#include <algorithm>

// ----- color code -----
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// ----- Class -----
template <typename T>
class PmergeMe
{
    public:
        // ----- constructor -----
        PmergeMe();
        PmergeMe(const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
        ~PmergeMe();

        // ----- member functions -----
        void parseInput(int argc, char **argv); // 入力を解析
        void mergeInsertSort(); // マージ挿入ソート
        void displayResults(double timeVector, double timeDeque);
        void displayList(); // 結果の表示

        private:
        void generateJacobsthalSequence(int n); // ヤコビアン数列を生成
        void mergeInsertSortVector(); // vectorのマージ挿入ソート
        void mergeInsertSortDeque(); // dequeのマージ挿入ソート
        void printVector(); // vectorの表示
        std::vector<std::pair<int, int> > createPairs(const std::vector<int> &vec);
        void binaryInsert(T &container, const typename T::value_type &value);

        void splitVector(std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right);
        std::vector<size_t> generateGroupSizes(size_t n);

        std::vector<int> _vector;
        std::deque<int> _deque;
        std::vector<int> _jacobsthalSequence; // ヤコビアン数列を保存
        std::vector<size_t> _groupSizes; // グループサイズを保存
        std::vector<int> _bigger;
        std::vector<int> _smaller;
        std::vector<int> _pending;
};

#endif
