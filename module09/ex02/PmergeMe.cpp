#include "PmergeMe.hpp"

// ----- constructor -----
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj) {*this = obj;}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj) {
    if (this != &obj) {
        _vector = obj._vector;
        _deque = obj._deque;
        _groupSizes = obj._groupSizes;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// ----- member functions -----
void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty()) {
            throw std::invalid_argument("Empty argument");
        }

        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                throw std::invalid_argument("Invalid argument");
            }
        }

        int num = std::atoi(arg.c_str());
        if (num < 0 || num > std::numeric_limits<int>::max()) {
            throw std::out_of_range("Number out of range");
        }
        _vector.push_back(num);
        _deque.push_back(num);
    }

    std::cout << std::endl;
}

void PmergeMe::mergeInsertSort() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    // // copy for comparison
    // std::vector<int> stdSortVector = _vector;
    // std::sort(stdSortVector.begin(), stdSortVector.end());

    // 開始時間：vector
    clock_t startVector = clock();
    mergeInsertSortVector();
    // 終了時間：vector
    clock_t endVector = clock();
    double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

    // 開始時間：deque
    clock_t startDeque = clock();
    mergeInsertSortDeque();
    // 終了時間：deque
    clock_t endDeque = clock();
    double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:  ";
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    // // result : std::sort
    // std::cout << "\nstd::sort: " << std::endl << "        " << CYAN;
    // for (size_t i = 0; i < stdSortVector.size(); ++i) {
    //     std::cout << stdSortVector[i] << " ";
    //     if (i == stdSortVector.size() - 1) {
    //         std::cout << std::endl << RESET;
    //     }
    // }
    displayResults(timeVector, timeDeque);
}

void PmergeMe::mergeInsertSortVector() {
    if (_vector.size() <= 1) {
        return;
    }

    // 奇数の場合、最後の要素を取り出す
    int oddElement = -1;
    bool hasOddElement = false;
    if (_vector.size() % 2 == 1) {
        oddElement = _vector.back();
        _vector.pop_back();
        hasOddElement = true;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _vector.size(); i += 2) {
        int first = _vector[i];
        int second = -1;

        if (i + 1 < _vector.size()) {
            second = _vector[i + 1];
        }

        int bigger, smaller;
        if (first > second) {
            bigger = first;
            smaller = second;
        } else {
            bigger = second;
            smaller = first;
        }

        pairs.push_back(std::make_pair(bigger, smaller));
    }

    // 大きい方の要素を取り出す
    std::vector<int> biggers;
    for (size_t i = 0; i < pairs.size(); ++i) {
        biggers.push_back(pairs[i].first);
    }

    // 大きい要素をソート
    if (biggers.size() > 1) {
        _vector = biggers;
        mergeInsertSortVector();  // 再帰的にソート
        biggers = _vector;  // ソート後の結果を取得
    }

    std::vector<int> result = biggers;

    // 最初のペアの小さい方の要素を先頭に挿入
    if (!pairs.empty()) {
        int valueToInsert = pairs[0].second;
        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < valueToInsert) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, valueToInsert);
    }

    // 挿入順序を生成
    std::vector<size_t> insertOrder;
    _groupSizes = generateGroupSizes(pairs.size());

    size_t processed = 1; // 最初のペアはすでに処理済み
    for (size_t g = 0; g < _groupSizes.size() && processed < pairs.size(); ++g) {
        size_t currentGroup = _groupSizes[g];
        size_t actualGroupSize;

        if (processed + currentGroup <= pairs.size()) {
            actualGroupSize = currentGroup;
        } else {
            actualGroupSize = pairs.size() - processed;
        }

        for (size_t j = 0; j < actualGroupSize; ++j) {
            size_t idx = processed + j;
            if (idx < pairs.size()) {
                insertOrder.push_back(idx);
            }
        }
        processed += actualGroupSize;
    }

    // 挿入順序に従って小さい方の要素を挿入
    for (size_t i = 0; i < insertOrder.size(); ++i) {
        size_t idx = insertOrder[i];
        if (idx >= pairs.size())
            continue;

        int valueToInsert = pairs[idx].second;

        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < valueToInsert) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, valueToInsert);
    }

    // 奇数の場合、取り出していた要素を適切な位置に挿入
    if (hasOddElement) {
        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < oddElement) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, oddElement);
    }

    _vector = result;
}

void PmergeMe::mergeInsertSortDeque() {
    if (_deque.size() <= 1) {
        return;
    }

    // 奇数の場合、最後の要素を取り出す
    int oddElement = -1;
    bool hasOddElement = false;
    if (_deque.size() % 2 == 1) {
        oddElement = _deque.back();
        _deque.pop_back();
        hasOddElement = true;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < _deque.size(); i += 2) {
        int first = _deque[i];
        int second = -1;

        if (i + 1 < _deque.size()) {
            second = _deque[i + 1];
        }

        int bigger, smaller;
        if (first > second) {
            bigger = first;
            smaller = second;
        } else {
            bigger = second;
            smaller = first;
        }

        pairs.push_back(std::make_pair(bigger, smaller));
    }

    // 大きい方の要素
    std::deque<int> biggers;
    for (size_t i = 0; i < pairs.size(); ++i) {
        biggers.push_back(pairs[i].first);
    }

    // 大きい方の要素をソート
    if (biggers.size() > 1) {
        _deque = biggers;
        mergeInsertSortDeque();  // 再帰的にソート
        biggers = _deque;  // ソート後の結果を取得
    }

    // 結果配列を初期化
    std::deque<int> result = biggers;

    // 最初のペアの小さい方の要素を挿入
    if (!pairs.empty()) {
        int valueToInsert = pairs[0].second;
        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < valueToInsert) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, valueToInsert);
    }

    std::vector<size_t> insertOrder;
    std::vector<size_t> groupSizes = generateGroupSizes(pairs.size());

    size_t processed = 1; // 最初のペアはすでに処理済み
    for (size_t g = 0; g < groupSizes.size() && processed < pairs.size(); ++g) {
        size_t currentGroup = groupSizes[g];
        size_t actualGroupSize;

        if (processed + currentGroup <= pairs.size()) {
            actualGroupSize = currentGroup;
        } else {
            actualGroupSize = pairs.size() - processed;
        }

        for (size_t j = 0; j < actualGroupSize; ++j) {
            size_t idx = processed + j;
            if (idx < pairs.size()) {
                insertOrder.push_back(idx);
            }
        }
        processed += actualGroupSize;
    }

    // 挿入順序に従って小さい方の要素を挿入
    for (size_t i = 0; i < insertOrder.size(); ++i) {
        size_t idx = insertOrder[i];
        if (idx >= pairs.size())
            continue;

        int valueToInsert = pairs[idx].second;

        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < valueToInsert) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, valueToInsert);
    }

    // 奇数の場合、取り出していた要素を適切な位置に挿入
    if (hasOddElement) {
        size_t left = 0;
        size_t right = result.size();

        while (left < right) {
            size_t mid = left + (right - left) / 2;
            if (result[mid] < oddElement) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        result.insert(result.begin() + left, oddElement);
    }

    _deque = result;
}

std::vector<size_t> PmergeMe::generateGroupSizes(size_t n) {
    std::vector<size_t> sizes;
    if (n == 0)
        return sizes;

    // 最初の2つは固定
    sizes.push_back(2);

    if (n == 1)
        return sizes;
    sizes.push_back(2);

    size_t sum = sizes[0] + sizes[1];

    size_t k = 2;
    while (sum < n) {
        size_t power = static_cast<size_t>(1) << (k + 1);
        size_t nextSize = power - sizes.back();
        sizes.push_back(nextSize);
        sum += nextSize;
        ++k;
    }

    return sizes;
}

void PmergeMe::displayResults(double timeVector, double timeDeque) {
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << timeVector << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << timeDeque << " us" << std::endl;
}
